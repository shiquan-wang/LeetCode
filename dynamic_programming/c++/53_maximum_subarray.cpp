#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
//给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和
//1 确定dp数组（dp table）以及下标的含义
// dp[i]：包括下标i之前的最大连续子序列和为dp[i]。

//2 确定递推公式
// dp[i]只有两个方向可以推出来：

// dp[i - 1] + nums[i]，即：nums[i]加入当前连续子序列和
// nums[i]，即：从头开始计算当前连续子序列和
// 一定是取最大的，所以dp[i] = max(dp[i - 1] + nums[i], nums[i]);

//3 dp数组如何初始化
// 从递推公式可以看出来dp[i]是依赖于dp[i - 1]的状态，dp[0]就是递推公式的基础。

// dp[0]应该是多少呢?

// 更具dp[i]的定义，很明显dp[0]因为为nums[0]即dp[0] = nums[0]。

//4 确定遍历顺序
// 递推公式中dp[i]依赖于dp[i - 1]的状态，需要从前向后遍历。

//5 举例推导dp数组
class Solution{
public:
    int maxSubArray(vector<int>& nums){
        if(nums.size() == 1) return nums[0];

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int res = dp[0];
        for(int i = 1; i < nums.size(); i++){
            // if(dp[i-1] + nums[i] > dp[i-1]){
            //     dp[i] = dp[i-1] + nums[i];
            // }else{
            //     dp[i] = nums[i];
            // }
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            if(res < dp[i]){
                res = dp[i];
            }
            //cout<<dp[i]<<"\t";
        }
        return res;
    }

    int greedy(vector<int>& nums){
    //贪心法， 局部最优的情况下，并记录最大的“连续和”，可以推出全局最优。
    //从代码角度上来讲：遍历nums，从头开始用count累积，如果count一旦加上nums[i]变为负数，那么就应该从nums[i+1]开始从0累积count了，因为已经变为负数的count，只会拖累总和
        int res = INT32_MIN;
        int count = 0;
        for(int i = 0; i < nums.size(); ++i){
            count += nums[i];
            if(count > res) res = count;
            if(count <= 0){
                count = 0;
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution s;
    int res = s.maxSubArray(nums);
}