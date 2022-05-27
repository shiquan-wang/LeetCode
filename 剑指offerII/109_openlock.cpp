/* 
你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为 '0'，'0' 变为 '9' 。
每次旋转都只能旋转一个拨轮的一位数字。锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，
这个锁将会被永久锁定，无法再被旋转。字符串 target 代表可以解锁的数字，你需要给出解锁需要的最小旋转次数，如果无论如何不能解锁，返回 -1 。\

思路：寻找最小旋转次数使用广度优先搜索，
具体地，我们在一开始将 (0000, 0) 加入队列，并使用该队列进行广度优先搜索。在搜索的过程中，设当前搜索到的数字为 status，旋转的次数为step，我们可以枚举 status 通过一次旋转得到的数字。
设其中的某个数字为 next_status，如果其没有被搜索过，我们就将(next_status,step+1) 加入队列。如果搜索到了target，我们就返回其对应的旋转次数。
为了避免搜索到死亡数字，我们可以使用哈希表存储 deadends 中的所有元素，这样在搜索的过程中，我们可以均摊O(1) 地判断一个数字是否为死亡数字。同时，我们还需要一个哈希表存储所有搜索到的状态，避免重复搜索。
如果搜索完成后，我们仍没有搜索到target，说明我们无法解锁，返回−1。
 */
#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution{
public:
    char num_prev(char x){//返回0-9字符的前一个字符
        return x == '0' ? '9' : x-1;
    }
    char num_succ(char x){//返回0-9字符的后一个字符
        return x == '9' ? '0' : x+1;
    }

    vector<string> get(string& status){//枚举status经过一次旋转可以得到的数字
        vector<string> ret;
        for(int i = 0; i < 4; ++i){
            char num = status[i];
            status[i] = num_prev(num);//第i位向前旋转
            ret.push_back(status);
            status[i] = num_succ(num);//第i位向后旋转
            ret.push_back(status);
            status[i] = num;
        }
        return ret;
    }
    int openLock(vector<string>& deadends, string target){
        if(target == "0000") return 0;//目标密码和初始密码相同，不需要旋转

        unordered_set<string> dead(deadends.begin(), deadends.end());//使用哈希表来存储所有的死亡数字，可以在O(1)的时间复杂度下判断一个数字是否是死亡数字
        if(dead.count(target) == 1) return -1;//target在死亡数组中，无法解锁。
        if(dead.count("0000") == 1) return -1;//0000在死亡数组中，开始直接锁死，无法解锁

        queue<pair<string, int>> q;//使用队列进行广度优先搜索，其中队列中存储数字以及到达这一步的旋转次数
        q.push({"0000", 0});
        unordered_set<string> seen = {"0000"};//存储所有旋转过的结果，避免重复搜索
        while (!q.empty())
        {
            auto [status, step] = q.front();
            q.pop();
            for(auto next_status : get(status)){//get(status)获取status可能旋转的结果，vector<string>
                if(next_status == target){//如果找到答案，返回step+1
                    return step + 1;
                }
                if(dead.count(next_status) == 1){//如果旋转结果在死亡数组中，不能选择
                    continue;
                }
                if(seen.count(next_status) == 1){//如果旋转的结果已经在之前出现过，尝试下一个
                    continue;
                }
                
                // q.push({next_status, step + 1}); 
                q.emplace(next_status, step + 1);//使用emplace可以节省空间，因此push操作首先是先复制对象数据到内存中，再进行入队，使用emplace避免这个拷贝操作
                // seen.emplace(next_status);//使用seen.
                seen.insert(move(next_status));//使用move将左值强制转换为右值，可以避免不必要的拷贝操作，将对象状态进行转移，没有内存的拷贝。
                
            }
        }
        
        return -1;
    }
/* 
执行用时：272 ms, 在所有 C++ 提交中击败了21.63%的用户
内存消耗：112.3 MB, 在所有 C++ 提交中击败了19.49%的用户
 */

/* 
优化，使用双向dfs,从两个方向出发减少搜索空间，
同时从两个方向开始搜索，一旦搜索到相同的值，意味着找到了一条联通起点和终点的最短路径。
对于「有解」、「有一定数据范围」同时「层级节点数量以倍数或者指数级别增长」的情况，「双向 BFS」的搜索空间通常只有「朴素 BFS」的空间消耗的几百分之一，甚至几千分之一。

[双向 BFS]的基本实现思路如下：

创建「两个队列」分别用于两个方向的搜索；
创建「两个哈希表」用于「解决相同节点重复搜索」和「记录转换次数」；
!!!!这个时候不能使用set来存储，需要使用map来存储到达status需要的相应步数
为了尽可能让两个搜索方向“平均”，每次从队列中取值进行扩展时，先判断哪个队列容量较少；
如果在搜索过程中「搜索到对方搜索过的节点」，说明找到了最短路径。
*/
    unordered_map<string, int> seen;
    unordered_map<string, int> seen2;
    int openLock_twobfs(vector<string> deadends, string target){
        if(target == "0000") return 0;//目标密码和初始密码相同，不需要旋转

        unordered_set<string> dead(deadends.begin(), deadends.end());//使用哈希表来存储所有的死亡数字，可以在O(1)的时间复杂度下判断一个数字是否是死亡数字
        if(dead.count(target) == 1) return -1;//target在死亡数组中，无法解锁。
        if(dead.count("0000") == 1) return -1;//0000在死亡数组中，开始直接锁死，无法解锁

        queue<pair<string, int>> q1, q2;//使用队列进行广度优先搜索，其中队列中存储数字以及到达这一步的旋转次数
        q1.emplace("0000", 0);
        q2.emplace(target, 0);
        seen.insert({"0000", 0});//存储所有旋转过的结果，避免重复搜索
        seen2.insert({target, 0});//存储倒序bfs所有搜索过的结果，避免重复搜索
        while (!q1.empty() && !q2.empty())
        {
            if(q1.size() < q2.size()){

            }
            // auto [status, step] = q.front();
            // q.pop();
            // for(auto next_status : get(status)){//get(status)获取status可能旋转的结果，vector<string>
            //     if(next_status == target){//如果找到答案，返回step+1
            //         return step + 1;
            //     }
            //     if(dead.count(next_status) == 1){//如果旋转结果在死亡数组中，不能选择
            //         continue;
            //     }
            //     if(seen.count(next_status) == 1){//如果旋转的结果已经在之前出现过，尝试下一个
            //         continue;
            //     }
                
            //     // q.push({next_status, step + 1}); 
            //     q.emplace(next_status, step + 1);//使用emplace可以节省空间，因此push操作首先是先复制对象数据到内存中，再进行入队，使用emplace避免这个拷贝操作
            //     // seen.emplace(next_status);//使用seen.
            //     seen.insert(move(next_status));//使用move将左值强制转换为右值，可以避免不必要的拷贝操作，将对象状态进行转移，没有内存的拷贝。
                
            // }
        }
        
        return -1;
    }

    int bfs(queue<pair<string, int>>& q, string target, unordered_set<string>& dead){
        auto [status, step] = q.front();
        q.pop();
        for(auto next_status : get(status)){//get(status)获取status可能旋转的结果，vector<string>
            // if(next_status == target){//如果找到答案，返回step+1
            //     return step + 1;
            // }
            if(dead.count(next_status) == 1){//如果旋转结果在死亡数组中，不能选择
                continue;
            }
            if(seen.count(next_status) == 1){//如果旋转的结果已经在之前出现过，尝试下一个
                continue;
            }
            
            // q.push({next_status, step + 1}); 
            q.emplace(next_status, step + 1);//使用emplace可以节省空间，因此push操作首先是先复制对象数据到内存中，再进行入队，使用emplace避免这个拷贝操作
            // seen.emplace(next_status);//使用seen.
            seen.insert({next_status, step + 1});//使用move将左值强制转换为右值，可以避免不必要的拷贝操作，将对象状态进行转移，没有内存的拷贝。
        }
        return -1;
    }
    
};

