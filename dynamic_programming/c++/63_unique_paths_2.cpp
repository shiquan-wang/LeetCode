#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0; i<m; ++i) {//第一列遇到障碍物前都只有一条途径可以到达，障碍物及障碍物后面的都无法抵达
            if(obstacleGrid[i][0] == 0){
                dp[i][0] = 1;
            }else{
                break;
            }
        }
        for(int j=0; j<n; ++j){//第一行同第一列
            if(obstacleGrid[0][j] == 0){
                dp[0][j] = 1;
            }else{
                break;
            }
        }
        for(int i=1; i<m; ++i){//遍历顺序，从1,1到m-1,n-1.
            for(int j=1; j<n; ++j){
                if(obstacleGrid[i][j] == 0){
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }else{
                    dp[i][j] = 0;
                }
            }
        }

        return dp[m-1][n-1];
    }
};