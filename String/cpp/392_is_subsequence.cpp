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

        for(int i = 0; i<26; ++i){
            dp[n][i] = n;
        }
    }

int main(){
    string s = "ace", t = "abcde";
    Solution s1;
    cout<<s1.isSubsequence(s, t);
}