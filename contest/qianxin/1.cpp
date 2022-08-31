#include<iostream>
#include<vector>

using namespace std;

class Solution{
private:
    vector<vector<int>> ans;
    vector<int> temp;
public:
    int DagPathNum(vector<vector<int>>& nodes){
        int n = nodes.size() - 1;
        temp.push_back(0);
        dfs(nodes, 0, n);
        return ans.size();
    }
    void dfs(vector<vector<int>> nodes, int i, int n){
        if(i == n){
            ans.push_back(temp);
            return;
        }
        for(int j = 0; j < nodes[i].size(); ++j){
            temp.push_back(nodes[i][j]);
            dfs(nodes, nodes[i][j], n);
            temp.pop_back();
        }
    }
};