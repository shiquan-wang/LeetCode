#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/* 
数组的每个下标作为一个阶梯，第 i 个阶梯对应着一个非负数的体力花费值 cost[i]（下标从 0 开始）。
每当爬上一个阶梯都要花费对应的体力值，一旦支付了相应的体力值，就可以选择向上爬一个阶梯或者爬两个阶梯。
请找出达到楼层顶部的最低花费。在开始时，你可以选择从下标为 0 或 1 的元素作为初始阶梯。
思路：动态规划
1， dp[i] 代表爬到第i个楼梯所耗费的最少体力
2， dp[i] = min(dp[i-1] + cost[i], dp[i-2] + cost[i])
3， 初始化，dp[0] = cost[0] dp[1] = cost[1]
4,  遍历顺序，从前往后
5， 举例推导dp数组
 */
class Solution{
private:

public:
    int minCostClimbingStairs(vector<int>& cost){
        vector<int> dp(cost.size() + 1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < cost.size(); ++i){
            dp[i] = min(dp[i-1] + cost[i], dp[i-2] + cost[i]);
        }
        // 注意最后一步可以理解为不用花费，所以取倒数第一步，第二步的最少值
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};