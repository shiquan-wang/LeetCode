#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/* 
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

你可以认为每种硬币的数量是无限的。
完全背包问题，
二维背包
1, dp[i][j], 使用0-i-1之间的硬币凑足金额j的最少个数为dp[i][j]
2, 递推公式， 如果不考虑使用coins[i]金额的硬币，那么dp[i][j] = dp[i-1][j],如果考虑使用coins[i]金额的硬币，那么dp[i][j] = dp[i-coins[i]] + 1
    因此dp[i][j] = min(dp[i-1][j], dp[i - 1 * coins[i] + 1, dp[i - 2 * coins[i] + 2], ... , dp[i - K * coins[i] + k)
3, 初始化，dp[0][0] = 0,凑足金额为0的钱币个数为0，因为递推过程中取较小值，因此初始化为int_max
4，遍历顺序，

二维背包超时，所以改为一维背包
1，dp[j], 凑足金额j的最少个数为dp[j]
2, dp[j] = min(dp[j], dp[j - coins[i] + 1]);
3, 初始化 dp[0] = 0 int_max
4, 遍历顺序，求最小数没有顺序
如果求组合数量，外层遍历物品，内层遍历背包
求排列数则是外层遍历背包，内层遍历物品
 */
class Solution{
public:
    int coinChange(vector<int>& coins, int  amount){
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for(int i = 0; i < coins.size(); ++i){
            for(int j = coins[i]; j <= amount; ++j){
                if(dp[j - coins[i]] != INT_MAX){//如果dp[j - coins[i]]是初始值则跳过
                    dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
                }
            }
        }

        if(dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};