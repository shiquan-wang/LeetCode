#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution{
public:
    long long res(long long a, long long b, int n){
        long long ans = 0;
        if(n == 1){
            return a;
        }
        if(n == 2){
            return b;
        }
        if(n == 3){
            return pow(a*b, 2);
        }
        if(n == 4){
            return pow(a, 4) * pow(b, 6);
        }
        
        
        long a_pow_1 = 2, a_pow2 = 4;
        long b_pow_1 = 2, b_pow2 = 6;
        long a_pow = 1, b_pow = 1;
        for(int i = 5; i <= n; ++i){
            a_pow = (a_pow_1+a_pow2) * 2;
            a_pow_1 = a_pow2;
            a_pow2 = a_pow;

            b_pow = (b_pow_1 + b_pow2) * 2;
            b_pow_1 = b_pow2;
            b_pow2 = b_pow;
        }
        long long temp = pow(10, 9) + 7;
        a = pow(a, a_pow);
        b = pow(b, b_pow);
        ans =  (a % temp)  * (b % temp);
        return ans % temp;
    }
};
int main(){
    long long a, b;
    int n;
    cin>>a>>b>>n;
    Solution s1;
    cout<<s1.res(a, b, n);
}