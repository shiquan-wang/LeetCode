#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int maxProfit(vector<int>& prices){
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        dp[0][0] = -prices[0];//持有股票
        dp[0][1] = 0;//不持有股票

        for(int i = 1; i < prices.size(); ++i){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]); //第i天持有股票剩余的金钱
            dp[i][1] = max(dp[i-1][0] + prices[i], dp[i-1][1]); //第i天不持有股票剩余的金钱
        }

        return dp[prices.size() - 1][1];
    }
};