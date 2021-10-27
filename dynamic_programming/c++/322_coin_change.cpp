#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int coinChange(vector<int>& coins, int amount){
        vector<int> dp(amount+1, INT16_MAX);
        dp[0] = 0;

        for(int i = 0; i < coins.size(); ++i){
            for(int j = coins[i]; j <= amount; ++j){
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }

        return dp[amount] != INT16_MAX ? dp[amount] : -1;
    } 
};
/* 
dp[j] = min[dp[j-coins[i]]] + 1 (i 从 0 到 j-1)
dp[0] = 0, dp[**] = INT16_MAX
外层遍历物品求的是组合数，完全背包背包容量是正序遍历
 */