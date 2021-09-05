#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution{
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums, int start_index){
        if(path.size() > 1){
            res.push_back(path);
        }

        unordered_set<int> used;
        for(int i = start_index; i < nums.size(); ++i){
            /* if((!path.empty() && nums[i] < path.back()) || (i > start_index && nums[i] == nums[i-1]) ){//同90要先排序才能(i > start_index && nums[i] == nums[i-1])这样筛选掉重复元素，否则不连续的重复元素无法筛选
                continue;
            } */
            if((!path.empty() && nums[i] < path.back()) || used.find(nums[i]) != used.end()){
                continue;
            }
            used.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums){
        res.clear();
        path.clear();
        backtracking(nums, 0);
        return res;
    }
};