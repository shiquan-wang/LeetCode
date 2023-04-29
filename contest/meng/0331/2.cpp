#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int main(){
    int n, k;
    cin>>n>>k;
    vector<int> vec1, vec2;
    int temp;
    for(int i = 0; i < n; ++i){
        cin>>temp;
        vec1.push_back(temp);
    }
    for(int i = 0;i < n; ++i){
        cin>>temp;
        vec2.push_back(temp);
    }

    vector<int> dp(n);
    int ans = -1;
    if(k > vec1[n-1]){
        dp[n-1] = 1;
        cout<<1;
    }
    // cout<<-1;

    for(int i = 1; i < n; ++i){
        if(k > vec1[i]){
            dp[i] = 1;
        }
        for(int j = 0; j < i; ++j){
            if(k > vec1[j]){

            }
        }
    }
    
}