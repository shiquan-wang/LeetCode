#include<iostream>
#include<vector>

using namespace std;
/* 
给定一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
思路：
 */
class Solution{
private:
    vector<int> subset;
    vector<vector<int>> res;
public:
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
    vector<vector<int>> subsets(vector<int>& nums){
        res.clear();
        subset.clear();
        backtracking(nums, 0);
        return res;
    }
};