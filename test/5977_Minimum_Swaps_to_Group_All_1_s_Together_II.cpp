#include<iostream>
#include<vector>

using namespace std;
//动态规划
//dp[i], 0-i-1的位置需要多少次交换可以完成目标
//dp[i] = dp[i-1] + 1(dp[i]是1而且和前面的1没有相邻) dp[i-1] (dp[i] 是1与前面相邻， 或者dp[i]是0)
//dp[i]初始化为0 
class Solution{
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
    }
};