#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/* 
给定一个长度为 n 的整数数组 nums ，其中 nums 是范围为 [1，n] 的整数的排列。还提供了一个 2D 整数数组 sequences ，其中 sequences[i] 是 nums 的子序列。
检查 nums 是否是唯一的最短 超序列 。最短 超序列 是 长度最短 的序列，并且所有序列 sequences[i] 都是它的子序列。对于给定的数组 sequences ，可能存在多个有效的 超序列 。

例如，对于 sequences = [[1,2],[1,3]] ，有两个最短的 超序列 ，[1,2,3] 和 [1,3,2] 。
而对于 sequences = [[1,2],[1,3],[1,2,3]] ，唯一可能的最短 超序列 是 [1,2,3] 。[1,2,3,4] 是可能的超序列，但不是最短的。
如果 nums 是序列的唯一最短 超序列 ，则返回 true ，否则返回 false 。
子序列 是一个可以通过从另一个序列中删除一些元素或不删除任何元素，而不改变其余元素的顺序的序列。

解法：拓扑排序
关键点在于，广度优先遍历搜索拓扑排序过程中，如果出现两个入度为0的节点，则说明序列不唯一
深度优先遍历 不好判断序列是否唯一,因为初始节点的选择存在多样性
 */
class Solution{
private:
    vector<vector<int>> edges;//邻接矩阵存储图
    vector<int> indeg;//存储每个节点的入度
    vector<int> ans;//存储拓扑排序路径
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences){
        if(sequences.size() == 0) return false;

        int n = nums.size();//nums范围是1-n
        
        // edges.assign(n, vector<int>(0));
        // indeg.assign(n, 0);
        edges.resize(n+1);
        indeg.resize(n+1);
        ans.clear();

        for(auto& seq : sequences){//构建邻接矩阵
            if(seq[0] > n || seq[0] < 1) return false;//nums中的元素范围是1-n,因此sequences中元素范围应该也是1-n,如果出现范围外的元素，返回false
            
            for(int i = 0; i < seq.size() - 1; ++i){
                if(seq[i+1] > n || seq[i+1] < 1) return false;//根据元素范围进行判断

                edges[seq[i]].push_back(seq[i+1]);//seq[i] 指向 seq[i+1]的一条边
                indeg[seq[i+1]]++;//seq[i+1]的入度加1
            }
        }

        queue<int> q;

        for(int i = 1; i < indeg.size(); ++i){//将入度为零的元素入队进行广度优先遍历
            if(indeg[i] == 0){
                q.push(i);//!!!!!!!第一次错误写成q.push(indeg[i])
                if(q.size() > 1){
                    return false;//如果同时出现两个入度为0的元素，则不存在唯一的一条拓扑排序
                }
            }
        }

        while (!q.empty())
        {
            if(q.size() != 1) return false;
            int temp = q.front();
            q.pop();
            ans.push_back(temp);

            for(int i = 0; i < edges[temp].size(); ++i){
                --indeg[edges[temp][i]];//遍历过的节点指向的所有节点的入度减1
                if(indeg[edges[temp][i]] == 0){
                    q.push(edges[temp][i]);
                }
            }
        }
        
        return ans == nums;
    }
};

int main(){
    vector<int> nums = {4, 1, 5, 2, 6, 3};
    vector<vector<int>> seq  = {{5, 2, 6, 3}, {4, 1, 5, 2}};
    Solution s1;
    bool res = s1.sequenceReconstruction(nums, seq);
    cout<<res;
}