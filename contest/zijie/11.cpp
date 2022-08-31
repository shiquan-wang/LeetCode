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
        int start = -1, end = 0;
        vector<int> b(2);
        // vector<int> vec(2);
        for(int i = 0; i < n; ++i){
            if(a[i] == 0){
//                 if(sum > ans){
//                     ans = sum;
//                     b[0] = start;
//                     b[1] = end;
//                     start = i;
//                     end = i;
//                 }
// //                 ans = max(ans, sum);
                sum = 1;
                start = i;
                // end = i+1;       
            }else{
                sum *= a[i];
                if(sum > ans){
                    ans = sum;
                    b[0] = start;
                    b[1] = i;
                }
                // end++;
            }
        }
        cout<<b[0]+2<<" "<<b[1]+1<<endl;
    }
    return 0;
}