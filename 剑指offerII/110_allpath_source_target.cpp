/* 
给定一个有 n 个节点的有向无环图，用二维数组 graph 表示，请找到所有从 0 到 n-1 的路径并输出（不要求按顺序）。
graph 的第 i 个数组中的单元都表示有向图中 i 号节点所能到达的下一些结点（译者注：有向图是有方向的，即规定了 a→b 你就不能从 b→a ），若为空，就是没有下一个节点了。

找到所有可能的路径，首先想到的是回溯搜索，
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution{
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    void backtracking(vector<vector<int>>& graph, int start_index, int target){
        if(start_index == target){//找到n-1
            res.push_back(path);
            return;
        }

        for(int i = 0; i < graph[start_index].size(); ++i){
            path.push_back(graph[start_index][i]);
            backtracking(graph, graph[start_index][i], target);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathSourceTarget(vector<vector<int>>& graph){
        res.clear();
        path.clear();
        path.push_back(0);
        backtracking(graph, 0, graph.size() - 1);
        return res;
    }
};