#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/* 
假如有一排房子，共 n 个，每个房子可以被粉刷成红色、蓝色或者绿色这三种颜色中的一种，你需要粉刷所有的房子并且使其相邻的两个房子颜色不能相同。

当然，因为市场上不同颜色油漆的价格不同，所以房子粉刷成不同颜色的花费成本也是不同的。每个房子粉刷成不同颜色的花费是以一个 n x 3 的正整数矩阵 costs 来表示的。

例如，costs[0][0] 表示第 0 号房子粉刷成红色的成本花费；costs[1][2] 表示第 1 号房子粉刷成绿色的花费，以此类推。

请计算出粉刷完所有房子最少的花费成本。
思路：动态规划
1， dp[i][0] dp[i][1] dp[i][2], 代表第i间房子刷红绿蓝的三种最低花费
2， dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i]][0], dp[i][1] dp[i][2] 同理
3， 初始化，dp[0][0] = cost[0][0] dp[0][1] = cost[0][1] dp[0][2] = cost[0][2]
4, 遍历顺序，i = 0; i < cost.size(); ++i
5, 举例推导dp数组
*/
class Solution{
public:
    int minCost(vector<vector<int>>& costs){
        // if(costs.size() == 1){
        //     return min
        // }
        int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0][0] = costs[0][0], dp[0][1] = costs[0][1], dp[0][2] = costs[0][2];
        for(int i = 1; i < n; ++i){
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + costs[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + costs[i][1];
            dp[i][2] = min(dp[i-1][1], dp[i-1][0]) + costs[i][2];
        }
        // if(dp[costs.size() - 1][0] < dp[costs.size() - 1][1]){
        //     return min(dp[costs.size() - 1][0], dp[costs.size() - 1][2]);
        // }else{
        //     return min(dp[costs.size() - 1][1], dp[costs.size() - 1][2]);
        // }
        return min(min(dp[n - 1][0], dp[n - 1][1]), dp[n-1][2]);
    }

    // int mincost(vector<vector<int>>& costs){
    //     jk
    // }
};