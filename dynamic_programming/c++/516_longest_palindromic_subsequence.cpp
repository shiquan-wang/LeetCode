#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution{
public:
    int longestPalindromeSubseq(string s){
        //dp[i][j] : s[i] - s[j] 最长的回文子序列长度
        
        //if s[i] == s[j], dp[i][j] = dp[i+1][j-1] + 2
        //if s[i] != s[j], dp[i][j] = max(dp[i+1][j], dp[i][j-1])

        //初始化，

        //遍历顺序，从下往上，从左往右

        //dp数组

        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int i = 0; i < s.size(); ++i) dp[i][i] = 1;
        for(int i = s.size() - 1; i >= 0; --i){
            for(int j = i+1; j < s.size(); ++j){
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};