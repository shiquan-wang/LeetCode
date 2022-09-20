#include<iostream>
using namespace std;

using namespace std;

typedef long long ll;

class Solution{
public:
    ll quick_pow(ll a, ll b, ll m){
        if(b == 0){
            return 1;
        }
        if(b % 2 == 1){
            return a * quick_pow(a, b-1, m) % m;
        }else{
            ll mul = quick_pow(a, b/2, m);
            return mul * mul % m;
        } 
    }
};