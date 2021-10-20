#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
//如何转化为01背包问题呢。
//假设加法的总和为x，那么减法对应的总和就是sum - x。
//所以我们要求的是 x - (sum - x) = S
//x = (S + sum) / 2
//此时问题就转化为，装满容量为x背包，有几种方法。
    int findTargetSumWays(vector<int>& nums, int target){
        int sum = 0;
        for(int i : nums) sum += i;
        if(abs(target) > sum) return 0;//target 的绝对值大于 sum ，无方案
        if((sum + target) % 2 == 1) return 0;
        int bag_size = (sum+target) / 2;
        
        vector<int> dp(bag_size + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); ++i){
            for(int j = bag_size; j >= nums[i]; --j){
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[bag_size];
    }
};

int main(){
    vector<int> nums = {1, 1, 1, 1, 1};
    Solution s;
    int res = s.findTargetSumWays(nums, 3);
}