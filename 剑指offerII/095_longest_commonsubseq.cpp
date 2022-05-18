#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
/* 
给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。

1, dp[i][j] text1[0] - text[i-1] 和 text2[0] - text[j-1]之间的最长公共子序列
2，if text[i-1] == text2[j-1] dp[i][j] = dp[i-1][j-1] + 1
   else dp[i][j] = max(dp[i-1][j], dp[i][j-1])
3, 初始化， 边界条件， dp[i][0] = 0 dp[0][j] = 0
4, 遍历顺序
5， 举例推导dp数组
 */
class Solution{
public:
    int longestCommonSubsequence(string text1, string text2){
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        for(int i = 1; i <= text1.size(); ++i){
            for(int j = 1; j <= text2.size(); ++j){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[text1.size()][text2.size()];
    }
};