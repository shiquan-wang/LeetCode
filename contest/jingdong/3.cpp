#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution{
public:
    void ans(int n){
        int ans = 0;
        if(n < 6){
            ans = 0;
        }else if(n == 6){
            ans = 1;
        }else{
            ans = 3*(n-6)*26;
            int temp = pow(10, 9) + 7;
            ans = (pow(26, n-6) * (n-4) * (n-5) / 2) % temp;
        }
        cout<<ans;
    }
};
int main(){
    int n;
    cin>>n;
    Solution s;
    s.ans(n);
}