#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/* 
如果一个由 '0' 和 '1' 组成的字符串，是以一些 '0'（可能没有 '0'）后面跟着一些 '1'（也可能没有 '1'）的形式组成的，那么该字符串是 单调递增 的。
我们给出一个由字符 '0' 和 '1' 组成的字符串 s，我们可以将任何 '0' 翻转为 '1' 或者将 '1' 翻转为 '0'。
返回使 s 单调递增 的最小翻转次数。
思路：动态规划
1，dp[0][i] dp[1] s[0] - s[i-1]以0结尾的的最小翻转次数和以1结尾的最小翻转次数
2，if s[i] == 0 dp[0][i] = dp[0][i-1],      dp[1][i] = min(dp[0][i-1], dp[1][i-1]) + 1
   if s[i] == 1 dp[0][i] = dp[0][i-1] + 1   dp[1][i] = min(dp[0][i-1], dp[1][i-1])
3，初始化 s[0] = 0, dp[0][0] = 0 dp[1[0] = 1
         s[0] = 1, dp[0][0] = 1 dp[1][0] = 0
4, 遍历顺序
 */
class Solution{
public:
    int minFlipsMonoIncr(string s){
        vector<vector<int>> dp(2, vector<int>(s.size(), 0));
        dp[0][0] = s[0] == '0' ? 0 : 1;
        dp[1][0] = s[0] == '1' ? 0 : 1;

        for(int i = 1; i < s.size(); ++i){
            dp[0][i] = dp[0][i-1] + (s[i] != '0');
            dp[1][i] = min(dp[0][i-1], dp[1][i-1]) +  (s[i] != '1');
        }
        return min(dp[0][s.size() - 1], dp[1][s.size() - 1]);
    }
};