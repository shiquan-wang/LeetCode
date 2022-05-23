/* 
给定一个正整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

思路一：回溯法
对于所有可能性的问题，使用回溯法可以找到所有可行解。

思路二：动态规划,转换为背包问题，
假设加法的总和为x,那么减法对应的总和是sum-x， x - (sum -x) = s => x = (s + sum )/2
问题转换为装满容量为x的背包，有几种方法
其中(s + sum )/2，如果s+sum为奇数，那么是无解的 同时如果s的绝对值大于sum,也是无解的

1, dp[j]，表示填满容量为j的背包有dp[j]中方法
 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
private:
    int sum;
    int res;
public:
    void backtracking(vector<int>& nums, int target, int index){
        if(index == nums.size()){
            if(sum == target){
                res ++;
            }
            return;
        }

        sum += nums[index];
        backtracking(nums, target, index + 1);
        sum -= nums[index];
            
        sum -= nums[index];
        backtracking(nums, target, index + 1);
        sum += nums[index];
    }

    int findTargetSumWays_backtracking(vector<int>& nums, int target){
        sum = 0;
        res = 0;
        backtracking(nums, target, 0);
        return res;
    }

    int findTargetSumWays(vector<int>& nums, int target){
        int sum = 0;
        for(auto item : nums){
            sum += item;
        }

        if(abs(target) > sum) return 0;
        if((sum + target) % 2 == 1) return 0;
        int bagSize = (target + sum) / 2;
        vector<int> dp(bagSize + 1, 0);

        dp[0] = 1;
        for(int i = 0; i < nums.size(); ++i){
            for(int j = bagSize; j >= nums[i]; j--){
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};