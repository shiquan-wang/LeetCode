#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int n, int k, int start_index){
        if(path.size() == k){//ending condition
            res.push_back(path);
            return;
        }

        for(int i = start_index; i <= n - (k - path.size()) + 1; ++i){//i<n-(k-path.size())+1 剪枝操作，当从i开始的数字个数不足k-path.size()个时，直接剪去这一分支的操作
            path.push_back(i);
            backtracking(n, k, i+1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k){
        res.clear();
        path.clear();
        backtracking(n, k, 1);
        return res;
    }
};