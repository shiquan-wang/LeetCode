#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution{
public:
    long res( long a, long b, int n){
       if(n == 1) return a;
       if(n == 2) return b;
       long ans = 0;
       for(int i = 3; i <= n; ++i){
            ans = pow(a*b, 2);
            a = b;
            b = ans;
       }
       long temp = pow(10, 9) + 7;
       return ans%temp;
    }
};
int main(){
     long a, b;
    int n;
    cin>>a>>b>>n;
    Solution s1;
    cout<<s1.res(a, b, n);
}