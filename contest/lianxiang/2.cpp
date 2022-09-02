#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution{
public:
    void min_num(string& str, int n){
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int maxlen = 1;
        int begin = 0;
        for(int i = 0; i < n; ++i){
            dp[i][i] = 1;
        }
        for(int l = 2; l <= n; ++l){
            for(int i = 0; i < n; ++i){
                int j = l+i-1;
                if(j >= n){
                    break;
                }

                if(str[i] != str[j]){
                    dp[i][j] = 0;
                }else{
                    if(j - i < 3){
                        dp[i][j] = 1;
                    }else{
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                
                if(dp[i][j] && j-i + 1 > maxlen){
                    maxlen = j - i + 1;
                    begin = i;
                }
            }
        }
        int ans = 0;
        ans += begin+1;
        int temp = begin + maxlen;
        ans += (n-1 - temp);
        cout<<ans;
    }
};
int main(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    Solution s1;
    s1.min_num(str, n);
}