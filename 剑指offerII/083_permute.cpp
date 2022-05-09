#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/* 
给定一个不含重复数字的整数数组 nums ，返回其 所有可能的全排列 。可以 按任意顺序 返回答案
 */
class Solution{
private:
    vector<vector<int>> res;
    vector<int> path;
    int path_num;
public:
    void backtracking(vector<int>& nums, vector<bool>& used){
        if(path.size() == nums.size()){//nums中的所有元素都已经在path中了
            res.push_back(path);
            return;
        }

        /* for(int i = start_index; i < nums.size(); ++i){
            if(used[i] == true){
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            path_num++;
            backtracking(nums, used, (i + 1) % nums.size(), path_num);
            path_num --;
            used[i] = false;
            path.pop_back();
        } */
        for(int i = 0; i< nums.size(); ++i){
            if(used[i] == true){
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            // path_num++;
            backtracking(nums, used);
            // path_num --;
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums){
        path.clear();
        res.clear();
        path_num = 0;
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }
};