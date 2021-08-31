#include<iostream>
#include<vector>

using namespace std;

class Solution{
private:
    vector<vector<int>> res;
    vector<int> subset;
    void backtracking(vector<int>& nums, int start_index){
        res.push_back(subset);
        if(start_index >= nums.size()){
            return;
        }

        for(int i = start_index; i < nums.size(); ++i){
            subset.push_back(nums[i]);
            backtracking(nums, i+1);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums){
        res.clear();
        subset.clear();
        backtracking(nums, 0);
        return res;
    }
};