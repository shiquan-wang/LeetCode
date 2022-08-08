#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int sum_1(int n){//计算小于等于n的所有奇数的和
        int ans = 0;
        for(int i = 0; i <= n; ++i){
            if(i % 2 == 1){
                ans += i;
            }
        }
        return ans;
    }
    int sum_2(int n){
        int ans = 0;
        for(int i = 0; i <= n; ++i){
            if(i % 2 == 0){
                ans += 2*i;
            }
        }
        return ans;
    }
    int sum(int n){
        int ans = 0;
        if(n % 2 == 1){
            int x = n/2;
            int a = sum_1(n);
            int b;
            if(x % 2 == 1){
                b = sum_2(x - 1);
            }else{
                b = sum_2(x);
            }
            ans = a-b;
        }else{
            return sum(n-1);
        }
        
        return ans;
    }
};
int main(){
    int t;
    cin>>t;
    vector<int> vec;
    int n;
    while (t--)
    {
        cin>>n;
        vec.push_back(n);
    }
    Solution s1;
    for(auto item : vec){
        cout<<s1.sum(item)<<endl;
    }
}