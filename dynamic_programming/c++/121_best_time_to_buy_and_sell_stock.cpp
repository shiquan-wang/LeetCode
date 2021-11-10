#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    int maxProfit(vector<int>& prices){
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        //dp[i][0] : 第i天持有股票的最大现金 dp[i][0] = max(dp[i-1][0], - prices[i]) 
        //          第i-1天就持有股票，那么就保持现状，所得现金就是昨天持有股票的所得现金 即：dp[i - 1][0]
        //          第i天买入股票，所得现金就是买入今天的股票后所得现金即：-prices[i] 因为只能交易一次，所以买入当天的现金为-prices[i]，如果可以买入卖出多次，dp[i-1][1] - prices[i]
        //dp[i][1] : 第i天不持有股票的最大现金
        //          第i-1天就不持有股票，那么就保持现状，所得现金就是昨天不持有股票的所得现金 即：dp[i - 1][1]
        //          第i天卖出股票，所得现金就是按照今天股票佳价格卖出后所得现金即：prices[i] + dp[i - 1][0]
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < prices.size(); ++i){
            dp[i][0] = max(dp[i-1][0], - prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
        }

        return dp[prices.size() - 1][1];
    }
};