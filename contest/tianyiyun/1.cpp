#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution{
public:
    int heart(int a, int h, int b, int k){
        int ans = 0;
        while (h > 0 && k > 0)
        {
            ans += a;
            ans += b;
            h -= b;
            k -= a;
            cout<<ans<<h<<k;
        }
        if(h > 0){
            ans += a*10;
        }else if(k > 0){
            ans += b*10;
        }
        return ans;
    }
    long long heart3(int a, int h, int b, int k){
        long long ans = 0;
        float temp1= ceil(float(h)/float(b)), temp2 = ceil(float(k)/float(a));
        // cout<<temp1<<temp2;
        int temp = min(temp1, temp2);
        // cout<<temp;
        ans += temp*(a+b);
        h -= temp*b;
        k -= temp*a;

        if(h == 0 && k == 0){
            return ans;
        }
        if(h > 0){
            ans += a*10;
        }else if(k > 0){
            ans += b*10;
        }
        return ans;
    }
    long long heart2(int a, int h, int b, int k){
        long long ans = 0;
        int temp1= h/b, temp2 = k/a;
        int temp = min(temp1, temp2) + 1;
        // cout<<temp;
        ans += temp*(a+b);
        h -= temp*b;
        k -= temp*a;
        if(h > 0){
            ans += a*10;
        }
        if(k > 0){
            ans += b*10;
        }
        return ans;
    }
};

int main(){
    int a, h, b, k;
    cin>>a>>h>>b>>k;
    Solution s1;
    cout<<s1.heart3(a, h, b, k);
}