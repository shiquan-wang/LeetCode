#include<iostream>
#include<vector>

using namespace std;
/* 
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
问总共有多少条不同的路径？
思路：动态规划
1，dp[i][j] 到达左边(i, j)的路径数目
2, 因为到达(i,j)的坐标可以是(i-1, j)或者(i, j-1)所以dp[i][j] = dp[i-1][j] + dp[i][j-1]
3, 边界条件及初始化，dp[0][0] - dp[0][m] == 1, dp[0][0] - dp[n][0] == 1,
4, 遍历顺序，
5, 举例推导
 */
class Solution{
public:
    int uniquePaths(int m, int n){
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};