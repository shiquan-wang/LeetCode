#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int start_index){
        if(sum >= target){
            if(sum == target){
                res.push_back(path);
            }
            return;
        }

        for(int i = start_index; i < candidates.size() && sum + candidates[i] <=target; ++i){
            if(i > start_index && candidates[i] == candidates[i-1]){//去除重复元素，即横向遍历时不能选择之前已经选择过的元素，横向不能重复，
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i+1);
            path.pop_back();
            sum -= candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        res.clear();
        path.clear();
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return res;
    }
};