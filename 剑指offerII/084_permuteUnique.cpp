#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;


/* 
给定一个可包含重复数字的整数集合 nums ，按任意顺序 返回它所有不重复的全排列。

考虑重复元素一定要优先排序
 */
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
            if(st.find(nums[i]) != st.end()){//去重,即相同的数字不能都作为排列的开始数字
                continue;
            }
            if(used[i] == true) continue;//避免使用选择过的元素，
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

class Solution1{
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    void backtracking(vector<int>& nums, vector<bool>& used){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); ++i){
            if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false){
                continue;
            }
            if(used[i] == true){
                continue;
            }

            path.push_back(nums[i]);
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
        sort(nums.begin(), nums.end());
        
    }
};