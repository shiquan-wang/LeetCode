#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution{
private:
    vector<vector<int>> res;
    vector<int> path;

public:
    void backtracking(vector<int>& nums, vector<bool>& used){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }

        unordered_set<int> st;
        for(int i = 0; i < nums.size(); ++i){
            if(st.find(nums[i]) != st.end()){//去重
                continue;
            }
            if(used[i] == true) continue;//避免使用用过的元素
            path.push_back(nums[i]);
            st.insert(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums){
        res.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }
};