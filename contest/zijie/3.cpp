#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    void ans(vector<int>& nums){
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > 0){
                ans += nums[i];
            }
        }
        cout<<ans;
    }
};
int main(){
    vector<int> vec;
    int k;
    int item;
    cin>>k;
    for(int i = 0; i < k; ++i){
        cin>>item;
        vec.push_back(item);
    }
    Solution s1;
    s1.ans(vec);
}