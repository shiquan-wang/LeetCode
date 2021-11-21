#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int maxProfit(vector<int>& prices){
        vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
        dp[0][0] = 0; dp[0][1] = -prices[0]; dp[0][2] = 0; dp[0][3] = -prices[0]; dp[0][4] = 0;
        for(int i = 1; i < prices.size(); ++i){
            dp[i][0] = dp[i-1][0];//没有任何操作
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);//第一次买入，前一天已经买入了或者第i天买入
            dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);//第一次卖出，前一天已经卖出了或者第i天卖出
            dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);//第二次买入，前一天已经买入了或者第i天买入
            dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i]);//第二次卖出，前一天已经卖出了或者第i天卖出
            for(int tmp : dp[i]){
                cout<<tmp;
            }
            cout<<endl;
        }

        return dp[prices.size()-1][4];
    }
};

int main(){
    vector<int> prices = {1, 2, 3, 4, 5};
    Solution s;
    int res = s.maxProfit(prices);
}