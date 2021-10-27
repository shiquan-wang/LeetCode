#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int climbStairs(int n){
        if(n == 1 || n == 2) return n;
        vector<int> dp(n);
        dp[0] = 1; dp[1] = 2;
        for(int i = 2; i < n; ++i){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n-1];
    }
    int climbStairs2(int n){
        if(n ==1 || n == 2) return n;
        int dp[3];
        dp[1] = 1; dp[2] = 2;
        for(int i = 3; i <= n; i++){
            int sum = dp[1] + dp[2];
            dp[1] = dp[2];
            dp[2] = sum;
        }
        return dp[2];
    }

    int climbStairs3(int n, int m){//每次可以跨越1-m个阶梯
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(i - j >= 0) dp[i] += dp[i - j];
            }
        }
        return dp[n];
    }
};