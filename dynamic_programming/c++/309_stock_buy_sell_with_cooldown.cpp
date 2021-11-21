#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int maxProfit(vector<int>& prices){
        if(prices.size() == 0) return 0;

        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));

        dp[0][0] = -prices[0];

        for(int i = 1; i < prices.size(); ++i){
            dp[i][0] = max(dp[i-1][0], max(dp[i-1][3] - prices[i], dp[i-1][1] - prices[i]));
            dp[i][1] = max(dp[i-1][1], dp[i-1][3]);
            dp[i][2] = dp[i-1][0] + prices[i];
            dp[i][3] = dp[i-1][2];
        }
        return max(dp[prices.size()-1][3], max(dp[prices.size()-1][1], dp[prices.size()-1][2]));
    }
};

/* 
dp数组：
    dp[i][0] 买入股票状态
    dp[i][1] 卖出股票状态， 两天前就就卖出股票，
    dp[i][2] 卖出股票状态，今天刚卖出股票
    dp[i][3] 今天是冷冻期状态，不可操作

递推公式：
    dp[i][0] = max( dp[i-1][0], max(dp[i-1][3] - prices[i], dp[i-1][1] - prices[i]) )
        前一天已经是持有股票的状态 dp[i-1][0]
        今天刚买入股票
            前一天是冷冻期（状态四）， 今天买入， dp[i-1][3] - prices[i]
            前一天是保持卖出股票的状态（状态二），dp[i-1][2] - prices[i]
    
    dp[i][1] = max( dp[i-1][1], dp[i-1][3])
        前一天就是状态二 dp[i-1][1]
        前一天是冷冻期 dp[i-1][3]
    
    dp[i][2] = dp[i-1][0] + prices[i]
        只有一个操作，昨天买入股票的状态（状态一），今天卖出

    dp[i][3] = dp[i-1][2]
        昨天卖出了股票（状态三）


初始化：
    dp[0][0] = -prices[0]
    dp[0][1] = 0
    dp[0][2] = 0
    dp[0][3] = 0



 */