#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int numSquares(int n){
        vector<int> sq(101, 0);
        for(int i = 0; i <= 100; ++i){//初始化物品信息，w[] v[]
            sq[i] = i * i;
        }

        vector<int> dp(n+1, INT16_MAX);
        dp[0] = 0;

        for(int i = 0; i < sq.size() && (sq[i] <= n); ++i){
            for(int j = sq[i]; j <= n; ++j){
                dp[j] = min(dp[j], dp[j - sq[i]] + 1);
            }
        }

        return dp[n];

    }
};