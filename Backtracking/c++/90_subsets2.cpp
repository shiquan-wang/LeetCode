#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums, int start_index){
        res.push_back(path);
        if(start_index >= nums.size()){
            return;
        }

        for(int i = start_index; i < nums.size(); ++i){
            if(i > start_index && nums[i] == nums[i-1]){//横向遍历时不能重复选择元素，!!要先对nums进行排序才能这样筛选掉重复元素
                continue;
            }
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        res.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return res;
    }
};