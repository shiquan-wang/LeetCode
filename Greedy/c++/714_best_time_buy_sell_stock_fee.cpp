#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int maxProfit(vector<int>& prices, int fee){
        int res = 0;
        int minPrice = prices[0];
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i] < minPrice) minPrice = prices[i];//情况二：前一天是收获利润区间里的最后一天（相当于真正的卖出了），今天要重新记录最小价格了。

            if(prices[i] >= minPrice && prices[i] <= minPrice + fee){//情况三：不作操作，保持原有状态（买入，卖出，不买不卖）
                continue;
            }

            if(prices[i] > minPrice + fee){
                res += prices[i] - minPrice - fee;
                minPrice = prices[i] - fee;//情况一：收获利润的这一天并不是收获利润区间里的最后一天（不是真正的卖出，相当于持有股票），所以后面要继续收获利润。
            }
        }
        return res;
    }
};