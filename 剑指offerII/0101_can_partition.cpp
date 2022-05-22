#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/* 
给定一个非空的正整数数组 nums ，请判断能否将这些数字分成元素和相等的两部分。
思路：
首先累加计算总和是否是偶数，如果是奇数直接返回false
将数组排序，回溯法寻找一组和为总和一半的数组
超时

动态规划，将其转换为背包问题
背包容量为sum/2
物品重量是nums[i], 价值是nums[i]
物品不可重复放入(01背包)
1, dp[j] 容量为j的背包可以装物品的最大价值。容量为j时最大可以凑成的子集和为dp[j]
2, dp[j] = max(dp[j], dp[j - nums[i] + nums[i]]);
3, dp[0] = 0
4, 遍历顺序，一维滚动数组遍历时先遍历物品，再倒序遍历背包体积
5，举例推导dp数组
 */
class Solution{
private:
    vector<vector<int>> res;
    vector<int> path;
    int path_sum;
public:
    void backtracking(vector<int>& nums, int start_index, int target){
        if(path_sum >= target){
            if(path_sum == target){
                res.push_back(path);
            }
            return;
        }

        for(int i = start_index; i < nums.size() && nums[i] <= target; ++i){
            path.push_back(nums[i]);
            path_sum += nums[i];
            backtracking(nums, i+1, target);
            path_sum -= nums[i];
            path.pop_back();
        }
    }
    bool canPartition1(vector<int>& nums){//回溯法，超时
        int sum = 0;
        for(auto item : nums){
            sum += item;
        }
        if(sum % 2 == 1){//nums数组总和为奇数
            return false;
        }
        int target = sum/2;
        sort(nums.begin(), nums.end());

        res.clear();
        path.clear();
        path_sum = 0;
        backtracking(nums, 0, target);

        if(res.size() > 0){
            return true;
        }
        return false;
    }

    bool canPartition(vector<int>& nums){
        vector<int> dp(10001, 0);//dp数组size大小应该是和sum/2一样大，但是因为元素小于100且个数小于200，因此避免遍历数组计算sum，将dp数组长度直接固定为10001

        int sum = 0;
        for(int item : nums){
            sum += item;
        }
        if(sum % 2 == 1) return false;
        int target = sum / 2;

        for(int i = 0; i < nums.size(); ++i){
            for(int j = target; j >= nums[i]; --j){
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        } 

        if(dp[target] == target){
            return true;
        }
        return false;
    }
};