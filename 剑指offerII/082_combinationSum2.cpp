#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/* 
给定一个可能有重复数字的整数数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次，解集不能包含重复的组合。 

 */
class Soltuion{
private:
    vector<int> path;
    vector<vector<int>> res;
    int path_count;
    
public:
    void backtracking(vector<int>& candidates, int target, int start_index){
        if(path_count >= target){
            if(path_count == target){
                res.push_back(path);
            } 
            return;
        }

        for(int i = start_index; i < candidates.size() && path_count + candidates[i] <= target; ++i){
            if(i > start_index && candidates[i] == candidates[i-1]){//去除重复元素，每一层遍历时不能选择重复的元素，1, 2, 2, 2, 5 第一个数字选择1，第二个数字可选2, 2, 2, 5，此时，2不能重复，因此只有2, 5两个选择。
                continue;
            }
            path.push_back(candidates[i]);
            path_count += candidates[i];
            backtracking(candidates, target, i+1);
            path_count -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        path.clear();
        res.clear();
        path_count = 0;
        //vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return res;
    }
};