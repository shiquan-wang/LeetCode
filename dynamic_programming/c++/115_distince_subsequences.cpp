#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int numDistinct(string s, string t){
    //dp[i][j]：以i-1为结尾的s子序列中出现以j-1为结尾的t的个数

    //s[i-1] 与 t[j-1] 相等 dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
    //s[i-1] 与 t[j-1] 不相等 dp[i][j] = dp[i-1][j]

    //初始化,dp[i][0] : 以i-1结尾的s中子序列 出现以-1结尾的 t (即空字符串)的个数, (以i-1为结尾的s可以随便删除元素，出现空字符串的个数) 一定是1, 
    //dp[0][j]  = 0, 因为空字符串 s[-1] 无论如何也不会变成 t
    //dp[0][0] = 1, 空字符串s，可以删除0个元素，变成空字符串t

    // 遍历顺序 ： 从上到下， 从左到右

    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    for(int i = 0; i <= s.size(); i++) dp[i][0] = 1;
    for(int j = 1; j <= t.size(); j++) dp[0][j] = 0;

    for(int i = 1; i <= s.size(); ++i){
        for(int j = 1; j <= t.size(); ++j){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
            cout<< dp[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return dp[s.size()][t.size()];
    }
};

int main(){
    string s = "baegg";
    string t = "bag";
    Solution s1;
    int res = s1.numDistinct(s, t);
}