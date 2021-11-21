#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int maxProfit(int k, vector<int>& prices){
        if(prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(k * 2 + 1, 0));

        for(int j = 1; j < 2 * k; j+=2){
            dp[0][j] = -prices[0];
        }
        for(int i = 1; i < prices.size(); ++i){
            for(int j = 0; j < 2 * k - 1; j += 2){
                dp[i][j+1] = max(dp[i-1][j+1], dp[i-1][j] - prices[i]);
                dp[i][j+2] = max(dp[i-1][j+2], dp[i-1][j+1] + prices[i]);
            }
        }

        return dp[prices.size() - 1][2 * k];
    }
};
/* 
dp[i][j] 第i天的状态为j,
    dp[i][0] 第i天不操作剩下的现金
    dp[i][1] 第i天第一次买入股票剩下的现金
    dp[i][2] 第i天第一次卖出股票剩下的现金
    ...
    ...
    dp[i][2 * k - 1] 第i天第k次买入股票剩下的现金
    dp[i][2 * k] 第i天第k次卖出股票剩下的现金

递推公式：
    dp[i][1] = max(dp[i-1][0] - prices[i], dp[i-1][1])
    dp[i][2] = max(dp[i-1][1] + prices[i], dp[i-1][2])

    dp[i][3] = max(dp[i-1][2] - prices[i], dp[i-1][3])
    dp[i][4] = max(dp[i-1][3] + prices[i], dp[i-1][4])

    for(int j = 1; j < 2*k; j += 2){
        dp[i][j] = max(dp[i-1][j-1] - prices[i], dp[i-1][j])
        dp[i][j+1] = max(dp[i-1][j-1] + priecs[i], dp[i-1][j+1])
    }

初始化：
    第0天没有操作， dp[0][0] = 0
    第0天第1次买入， dp[0][1] = -prices[0]
    第0天第1次卖出，dp[0][2] = 0 { dp[0][1] + prices[0]}
    第0天第2次买入，dp[0][3] = -prices[0] { dp[0][2] - prices[0]}
    第0天第1次卖出，dp[0][4] = 0 { dp[0][3] + prices[0]}
    ...
    ...
    第0天第k次买入， dp[0][2*k-1] = -prices[0]
    第0天第k次卖出， dp[0][2*k] = 0

    for(int j = 1; j < 2*k; j+=2){
        dp[0][j] = - prices[0]
    }


遍历顺序：
    从前向后，根据dp[i] 推导 dp[i+1]

推导dp数组
        
 */