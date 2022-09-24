#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    void get_ans(vector<long long> n, vector<long long> m, long long t){
        long long ans = 0;
        long long left = 0, right = 0;
        vector<long long> dp_n(n.size() + 1, 0);
        vector<long long> dp_m(m.size() + 1, 0);
        dp_n[1] = n[0];
        dp_m[1] = m[0];
        vector<vector<long long>> dp(n.size() + 1, vector<long long>(m.size() + 1, 0));
        for(long long i = 1; i <= n.size(); ++i){
            dp_n[i] = dp_n[i-1] + n[i-1];
            if(dp_n[i] > t){
                
                break;
            }
            left = i;
        }
        for(long long i = 1; i <= m.size(); ++i){
            dp_m[i] = dp_m[i-1] + m[i-1];
            if(dp_m[i] > t){ 
                break;
            }
            right = i;
        }
        for(long long i = 0; i < left; ++i){
            for(long long j = 0; j < right; ++j){
                dp[i][j] = dp_n[i] + dp_n[j];
                if(dp[i][j] > t){
                    continue;
                }
                long long temp = i + j;
                ans = max(ans, temp);
            }
        }
        cout<<ans;
    }
};
int main(){
    long long n, m, t;
    cin>>n>>m>>t;
    vector<long long> vec1;
    vector<long long> vec2;
    long long item;
    for(long long i = 0; i < n; ++i){
        cin>>item;
        vec1.push_back(item);
    }
    for(long long i = 0; i < m; ++i){
        cin>>item;
        vec2.push_back(item);
    }
    Solution s1;
    s1.get_ans(vec1, vec2, t);
}