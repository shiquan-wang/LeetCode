#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int k, int n, int path_sum, int start_index){
        if(path_sum > n){
            return;
        }

        if(path.size() == k){
            if(path_sum == n) res.push_back(path);
            else return;
        }

        for(int i = start_index; i <= 9 - (k - path.size()) + 1 ; ++i){
            path.push_back(i);
            path_sum += i;
            backtracking(k, n, path_sum, i+1);
            path_sum -= i;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n){
        res.clear();
        path.clear();
        backtracking(k, n, 0, 1);
        return res;
    }
};