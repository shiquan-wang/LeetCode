#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int maxProfit(vector<int>& prices, int fee){
        if(prices.size() == 1) return 0;

        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        //dp[i][0] 第i天不持有股票的最大收益
        //dp[i][1] 第i天持有股票的最大收益
        // 重要！！英文版题目没有说明，一次交易支付一次手续费指的是卖出的时候支付，买入的时候不需要手续费
        dp[0][1] = -prices[0] - fee;
        for(int i = 1; i < prices.size(); ++i){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }

        return dp[prices.size() - 1][0];
    }
};