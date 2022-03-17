#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution{
public:
    int countSubstrings(string s){
        vector<vector<bool>> dp(s.length(), vector(s.length(), false));
        int res = 0;
        for(int i = s.length() - 1; i >= 0; --i){
            for(int j = i; j < s.length(); ++j){
                if(s[i] == s[j]){
                    if(j - i <= 1){
                        res++;
                        dp[i][j] = true;
                    }else if(dp[i+1][j-1]){
                        res++;
                        dp[i][j] = true;
                    }
                }
            }
        }

        return res;
    }

    int countSubstrings2(string s){
        int n = s.size(), ans = 0;
        for(int i = 0; i < 2 * n - 1; ++i){
            int l  = i/2, r = i/2 + i % 2;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                --l; ++r; ++ans;
            }
            
        }
        return ans;
    }
};