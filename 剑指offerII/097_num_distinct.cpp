#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution{
public:
    int numDistinct(string s, string t){
        if(s.size() < t.size()){
            return false;
        }
        int m = s.size(), n = t.size();
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1));
        for(int i = 0; i <= m; ++i){
            dp[i][n] = 1;
        }
        for (int i = m - 1; i >= 0; i--) {
            char sChar = s.at(i);
            for (int j = n - 1; j >= 0; j--) {
                char tChar = t.at(j);
                if (sChar == tChar) {
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        return dp[0][0];
    }
};