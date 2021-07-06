#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int longestPalindromeSubseq(string s){
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        //base_case
        for(int i = 0; i < n; ++i){
            dp[i][i] = 1;
        }
        //状态转移,从dp数组的右下角向上遍历，
        for(int i = n-2; i >= 0; --i){
            for(int j = i+1; j < n; ++j){
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        return dp[0][n-1];
    }
};

int main(){
    string s1 = "bbbab";
    Solution s;
    cout<<s.longestPalindromeSubseq(s1);
}