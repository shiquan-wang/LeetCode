#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{
public:
    bool isSubsequence(string s, string t){
        //双指针
        int i = 0, j = 0;
        for(int i = 0, j = 0; i < t.length() && j < s.length();){
            if(s[i] == t[j]){
                ++i; ++j;
            }else{
                ++j;
            }
        }
        if(i == s.length()){
            return true;
        }else{
            return false;
        }
    }

    bool isSubsequence2(string s, string t){
        //dp
        //dp[i][j] : 从0 —— i-1, 0 —— j-1, 相同子序列的长度
        //递推公式： dp[i][j] = dp[i-1][j-1] + 1, if s[t-1] == t[j-1];
        //          dp[i][j] = dp[i][j-1] ,if s[t-1] != t[j-1]
        //初始化：dp[0][0] = dp[i][0] = 0
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));

        for(int i = 1; i <= s.size(); ++i){
            for(int j = 1; j <= t.size(); ++j){
                if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = dp[i][j-1];
            }
        }
        if(dp[s.size()][t.size()] == s.size()) return true;
        else return false;
    }
};