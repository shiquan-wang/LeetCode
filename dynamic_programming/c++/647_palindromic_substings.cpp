#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
public:
    int countSubstrings(string s){
        //dp[i][j] : i-j的子串是否是回文字符串

        //s[i] != s[j] dp[i][j] 一定是false
        //s[i] == s[j] case1: if i==j, 即s[i] s[j]是同一个字符，那么是回文字符串，dp[i][j] == true
        //             case2: if | i - j | == 1, i 与 j 相差为1， 例如aa, 那么dp[i][j] == true
        //             case3: if i 与 j 相差大于1， dp[i][j] 就看dp[i+1][j-1]的情况即可

        //初始化，全部为false

        //遍历顺序，dp[i][j] 依靠 dp[i+1][j-1](左下角), 因此遍历顺序从下到上，从左到右

        int res = 0;
        vector<vector<bool>> dp(s.size(), vector(s.size(), false));

        for(int i = s.size() - 1; i >= 0; --i){
            for(int j = i; j < s.size(); ++j){
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
};