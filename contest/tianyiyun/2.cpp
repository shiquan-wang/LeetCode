#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution{
public:
    long long min_money(int n, int a, int b){
        float two = a/2, three = b/3;
        long long  ans = 0;
        if(two < three){//双人船更便宜
            int nums = 0;
            if(n % 2 == 0){
                nums = n/2;
                ans += a * nums;
            }else{
                nums = ceil(n/2);
                long long temp1 = a*nums;
                long long temp2 = a*(nums-1) + b;
                ans = min(temp1, temp2);
            }
        }else{
            ans += b * ceil(n/3);
        }
        return ans;
    }
};
int main(){
    int T;
    int n, a, b;
    cin>>T;
    Solution s1;
    while (T--)
    {
        /* code */
        cin>>n>>a>>b;
        cout<<s1.min_money(n, a, b)<<endl;
    }
    
}