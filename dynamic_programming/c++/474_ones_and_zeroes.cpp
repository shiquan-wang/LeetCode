#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    int findMaxForm(vector<string>& strs, int m, int n){
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(string s : strs){
            int zeronum = 0, onenum = 0;
            for(char c : s){
                if(c == '1') onenum++;
                else zeronum++;
            }

            for(int i = m; i > zeronum; --i){
                for(int j = n; j > onenum; --j){
                    dp[i][j] = max(dp[i][j], dp[i-zeronum][j-onenum] + 1);
                }
            }
            for(int i = 0; i <= m; ++i){
                for(int j = 0; j <= n; ++j){
                    cout<<dp[i][j]<<" ";
                }
                cout<<endl;
            }
        }

        return dp[m][n];
    }
};

int main(){
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    Solution s;
    int res = s.findMaxForm(strs, 3, 3);
}