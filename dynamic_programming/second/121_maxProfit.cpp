#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/* 
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

 */
class Solution{
public:
    int maxProfit(vector<int>& prices){
        //dp[i][0] 第i天持有股票所得的最多现金
        //dp[i][1] 第i天不持有股票的最多现金
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));

        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for(int i = 1; i < prices.size(); ++i){
            dp[i][0] = max(dp[i-1][0], - prices[i]);
            dp[i][1] = max(dp[i-1][0] + prices[i], dp[i-1][1]);
        }
        return dp[prices.size()-1][1];
    }
};