#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution{
public:
    bool isSubsequence(string s, string t){
        int m = s.size(), n = t.size();
        int pl = 0, pr = 0;
        for(; pl < m && pr < n; ){
            if(s[pl] == t[pr]){
                ++pl; ++pr;
            }else{
                ++pr;
            }
        }
        if(pl == m){
            return true;
        }else{
            return false;
        }
    }
    bool isSubsequence2(string s, string t){
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(n+1, vector<int>(26, 0));
        //dp[i][j]代表从字符串t从位置i开始往后字符j第一次出现的位置。
        for(int i = 0; i<26; ++i){
            dp[n][i] = n; //n代表下一次出现的位置大于字符串长度即不存在下一个该字符
        }

        for(int i = n-1; i >= 0; --i){
            for(int j = 0; j < 26; ++j){
                if(t[i] == 'a' + j){
                    dp[i][j] = i;
                }else{
                    dp[i][j] = dp[i+1][j];
                }
            }
        }

        int add = 0;
        for(int i=0; i<m; ++i){
            if(dp[add][s[i] - 'a'] == n){
                return false;
            }
            add = dp[add][s[i] - 'a']+1;
        }
        return true;
        // 时间复杂度：O(m×∣Σ∣+n)，其中 n 为 s 的长度，m 为 t 的长度，Σ 为字符集，在本题中字符串只包含小写字母，∣Σ∣=26。预处理时间复杂度 O(m)，判断子序列时间复杂度 O(n)。
        // 如果是计算 k 个平均长度为 n 的字符串是否为 t 的子序列，则时间复杂度为 O(m×∣Σ∣+k×n)
        // 如果k > ∣Σ∣,则第二种解法用时短，
    }
};

int main(){
    string s = "axc", t = "ahbgdc";
    Solution s1;
    cout<<s1.isSubsequence2(s, t);
}