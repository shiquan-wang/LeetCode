#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int nums_search(int n){
        int ans = 0;
        for(int i = 0; i < n; ++i){
            ans += ((i/2)+1);
        }
        return ans;
    }
};
int main(){
    int n;
    cin>>n;
    Solution s1;
    cout<<s1.nums_search(n);
}