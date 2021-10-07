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
};