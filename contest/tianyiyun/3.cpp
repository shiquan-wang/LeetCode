#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution{
public:
    long long min_money(int n, int a, int b){
        float two = a/2, three = b/3;
        //优先2人轮船
        long long  ans1 = 0;
        int nums1 = 0;
        if(n % 2 == 0){
            nums1 = n/2;
            ans1 += a * nums1;
        }else{
            nums1 = ceil(n/2);
            long long temp1 = a*nums1;
            long long temp2 = a*(nums1-1) + b;
            ans1 = min(temp1, temp2);
        }
        //优先三人船
        long long  ans2 = 0;
        int nums2 = 0;
        if(n % 3 == 0){
            nums2 = n/3;
            ans2 = b * nums2;
        }else{
            nums2 = ceil(n/3);
            long long temp1 = b*nums2;
            long long temp2 = b*(nums2-1) + a;
            ans2 = min(temp1, temp2);
        }
        return min(ans1, ans2);
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