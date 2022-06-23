#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
/* 
有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。
省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。
给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。
返回矩阵中 省份 的数量。

思路：
将二维矩阵建为图，广度优先遍历或深度优先遍历来实现寻找连通分量个数的计算
 */
class Solution{
private:
    int ans;
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int city){
        // if(visited[city] != 0){
        //     return ;
        // }

        for(int i = 0; i < isConnected.size(); ++i){
            if(isConnected[city][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                dfs(isConnected, visited, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected){
        ans = 0;
        int citys = isConnected.size();
        vector<int> visited(citys, 0);//标记节点状态

        for(int i = 0; i < citys; ++i){
            if(visited[i] == 0){
                dfs(isConnected, visited, i);
                ++ans;
            }
        }

        return ans;
    }

    int bfs(vector<vector<int>>& isConnected){
        ans = 0;
        int citys = isConnected.size();
        vector<int> visited(citys, 0);//标记数组

        queue<int> q;
        for(int i = 0; i < citys; ++i){
            if(visited[i] != 0){
                continue;
            }
            q.push(i);
            
            while (!q.empty())
            {
                int temp = q.front();
                q.pop();
                visited[temp] = 1;
                for(int j = 0; j < citys; ++j){
                    if(isConnected[temp][j] == 1 && visited[j] == 0){
                        q.push(j);
                        // visited[isConnected[i][j]] = 1;
                    }
                }
            }
            ans++;
        }
        return ans;
    }
    
};
/* 
    并查集：
    基本概念：
    1并查集是一种数据结构   2合并 查找 集合（字典） 3关于连通分量的问题都可以使用并查集来解决   4添加 合并 查找的时间复杂度都是O(1) 5可以应用到在线算法中
数据结构    并查集跟树有些类似，只不过她跟树是相反的。在树这个数据结构里面，每个节点会记录它的子节点。在并查集里，每个节点会记录它的父节点。
    unordered_map<int, int> father;//记录父节点
如果节点是相互连通的（从一个节点可以到达另一个节点），那么他们在同一棵树里，或者说在同一个集合里，或者说他们的祖先是相同的。

初始化  当把一个新节点添加到并查集中，它的父节点应该为空
    void add(int x){
        if(map.count(x) == 0){
            map[x] = -1;
        }
    }

查找祖先 如果节点的父节点不为空，那就不断迭代。
    int find(int x){
        int root = x;
        if(father[root] != -1){
            root = father[root];
        }
        return root;
    }

合并两个节点    如果发现两个节点是连通的，那么就要把他们合并，也就是他们的祖先是相同的。这里究竟把谁当做父节点一般是没有区别的。
    void merge(int x, int y){
        int root_x = find[x];
        int root_y = find[y];

        if(root_x != root_y){
            father[root_x] = root_y;//将x的父节点的父节点指向y的父节点
        }
    }

两个节点是否连通 我们判断两个节点是否处于同一个连通分量的时候，就需要判断它们的祖先是否相同
    bool is_connected(int x, int y){
        return find(x) == find(y);
    }

查找祖先时如果树很深退化为了链表，那么时间复杂度较高，因此可以做一下路径压缩，也就是把树的深度固定为2
    int find(int x){
        int root = x;
        while(father[root] != -1){
            root = father[root];
        }

        //路径压缩
        while(x != root){
            int original_father = father[x];
            father[x] = root;
            x = original_father;
        }

        return root;
    }
     */
class UnionFind{
private:
    unordered_map<int, int> father;
    int ans = 0;
public:
    void add(int x){//并查集中添加元素
        if(father.count(x) == 0){
            father[x] = -1;
            ans++;//加入新元素时连通分量加一
        }
    }

    int find(int x){//查找x的祖先节点
        int root = x;
        while (father[root] != -1)
        {
            root = father[root];
        }

        //压缩路径，介绍后续使用到该路径上节点时的时间复杂度
        while (x != root)
        {
            int origin_father = father[x];
            father[x] = root;
            x = origin_father;
        }

        return root;
    }

    bool is_connected(int x, int y){
        return find(x) == find(y);
    }

    void merge(int x, int y){
        int root_x = find(x);
        int root_y = find(y);

        if(root_x != root_y){
            father[root_x] = root_y;
            ans--;//合并时连通分量数减一
        }
    }

    int get_ans(){
        return ans;
    }
};
class Solution2{
private:

public:
    int findCircleNum(vector<vector<int>>& isConnected){
        UnionFind uf;
        for(int i = 0; i < isConnected.size(); ++i){
            uf.add(i);
            for(int j = 0; j < isConnected.size(); ++j){
                // uf.add[j];
                if(isConnected[i][j] == 1){
                    uf.merge(i, j);
                }
            }
        }
        return uf.get_ans();
    }
    
};