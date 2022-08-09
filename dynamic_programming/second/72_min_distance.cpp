#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/* 
给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符

dp: dp[i][j]，以word1 0-i-1 转换为 word2 0-j-1的最小操作数

if word1[i-1] == word2[j-1] dp[i][j] == dp[i-1][j-1]
else 向word1中插入字符 dp[i][j] = dp[i][j-1] + 1,  原因：假设horse到ro的编辑距离为a,那么horse到ros的编辑距离不会超过a+1(word1中进行插入操作)
    向word1中删除一个字符（等价于向Word2中插入一个字符） dp[i][j] = dp[i-1][j] + 1 ,原因：假设hors到ros的编辑距离为b,那么horse到ros的编辑距离不会超过b+1(删除操作,删除e或者word2中添加e)
    修改word1中的一个字符，dp[i][j] = dp[i-1][j-1] + 1
 */
class Solution{
public:
    int minDistance(string word1, string word2){
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));//dp[i][j], word1以i-1结尾的字符串转变为 word2以j-1结尾的字符串的编辑距离

        for(int i = 0; i <= word1.size(); ++i){
            dp[i][0] = i;
        }
        for(int j = 0; j <= word2.size(); ++j){
            dp[0][j] = j;
        }
        
        for(int i = 1; i <= word1.size(); ++i){
            for(int j = 1; j <= word2.size(); ++j){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]}) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};