#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/* 
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

思路：动态规划
1, dp[i][j]定义为机器人移动至(i,j)的最小数字总和
2，机器人到达(i,j)的出发地点有(i-1, j) 和 (i, j-1), 因此dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
3, 初始化以及边界条件，0 < i < m  dp[i][0] = (dp[i-1][0] + grid[i][0])，因为只能向右和向下，所以第一列的每个坐标都只能是一直向下走到达的
    0 < i < n dp[0][i] = (dp[0][i-1] + grid[0][i])同理，第一行的每个坐标都是只能向右走到达的
4, 遍历顺序
5，举例推导dp数组
 */
class Solution{
public:
    int minPathSum(vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = grid[0][0];//初始化
        for(int i = 1; i < m; ++i){//将第一列初始化
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        for(int j = 1; j < n; ++j){//第一行初始化
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }

        for(int i = 1; i < m; ++i){//dp数组计算
            for(int j = 1; j < n; ++j){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        return dp[m-1][n-1];
    }
};