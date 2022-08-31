#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

const int maxn = 1e4 + 10;
typedef long long ll;

int main(){
    int n, t;
    cin>>t;
    int a[maxn];
    int item;
    while (t--)
    {
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>item;
            a[i] = item;
        }
        ll ans = 0, sum = 1;
        for(int i = 0; i < n; ++i){
            if(a[i] == 0){
                ans = max(ans, sum);
            }else{
                sum *= a[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}