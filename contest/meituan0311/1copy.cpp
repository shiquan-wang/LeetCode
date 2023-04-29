#include<iostream>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.size();
    if(n == 1){
        cout<<0;
        return 0;
    }
    vector<int> dp(n, 0);
    if(s[1] == s[0]){
        dp[1] = 1;
    }

    for(int i = 2; i < n; ++i){
        if(s[i] != s[i-1]){
            dp[i] = dp[i-1];
        }else{
            dp[i] = min(dp[i-2], dp[i-1]) + 1;
        }
    }
    cout<<dp[n-1];
}