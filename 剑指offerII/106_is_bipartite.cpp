#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/* 
存在一个 无向图 ，图中有 n 个节点。其中每个节点都有一个介于 0 到 n - 1 之间的唯一编号。

给定一个二维数组 graph ，表示图，其中 graph[u] 是一个节点数组，由节点 u 的邻接节点组成。形式上，对于 graph[u] 中的每个 v ，都存在一条位于节点 u 和节点 v 之间的无向边。该无向图同时具有以下属性：

不存在自环（graph[u] 不包含 u）。
不存在平行边（graph[u] 不包含重复值）。
如果 v 在 graph[u] 内，那么 u 也应该在 graph[v] 内（该图是无向图）
这个图可能不是连通图，也就是说两个节点 u 和 v 之间可能不存在一条连通彼此的路径。
二分图 定义：如果能将一个图的节点集合分割成两个独立的子集 A 和 B ，并使图中的每一条边的两个节点一个来自 A 集合，一个来自 B 集合，就将这个图称为 二分图 。

如果图是二分图，返回 true ；否则，返回 false 。
解题思路：深度优先搜索或者广度优先搜索
 */
class Solution{
private:
    // vector<bool> visited;//访问数组标志是否访问过该节点
    vector<int> color;//标志每个节点的颜色，0代表没有被访问，1代表红色，2代表绿色
public:
    bool isBipartite(vector<vector<int>>& graph){
        color.assign(graph.size(), 0);
        
        for(int i = 0; i < graph.size(); ++i){
            if(color[i] == 0){//graph[i]节点没有访问过，将其置为红色
                color[i] = 1;
                queue<int> q;//利用队列进行广度优先遍历
                q.push(i);
                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    int nei_color = color[node] == 1 ? 2 : 1;//如果node是红色则邻接节点应为绿色，反之亦然
                    for(int i : graph[node]){//遍历node的邻接节点
                        if(color[i] == 0){//邻接节点未遍历过，置为和node相反的颜色
                            q.push(i);//将node的邻接节点入队进行层次遍历
                            color[i] = nei_color;
                        }else if(color[i] != nei_color){//邻接节点已访问过而且颜色和node颜色相同
                            return false;
                        }
                    }
                }
                
            }
        }

        return true;
    }
};