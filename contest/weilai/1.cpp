#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+100;
int c[N], val[N], cnt[N], last[N], tot[N], n, k, p, R;
long ans = 0;
int main(){
    cin>>n>>k>>p;
    for(int i = 0; i < n; ++i){
        cin>>c[i]>>val[i];
    }
    for(int i = 1; i <= n; ++i){
        if(val[i] <= p) R = i;
        if(R >= last[c[i]]){
            tot[c[i]] = cnt[c[i]];
        }
        last[c[i]] = i;
        ans += tot[c[i]];
        cnt[c[i]]++;
    }
    cout<<ans<<endl;
    return 0;
}