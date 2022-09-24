#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution{
public:
    void get_ans(vector<int>& nums){
        // cout<<"true";
        // cout<<"false";
        // unordered_set<int> st;
        // st.insert(nums.size() + 1);
        vector<bool> dp(nums.size() + 1, false);
        dp[nums.size()] = true;
        for(int i = nums.size()-1; i >= 0; --i){
            for(int j = 1; j <= nums[i]; ++j){
                if(dp[j] == true){
                    dp[i] = true;
                    break;
                }
            }
        }
        if(dp[0]){
            cout<<"true";
        }else{
            cout<<"false";
        }
    }
};

int main(){
    int n;
    vector<int> nums;
    cin>>n;
    int item;
    for(int i = 0; i < n; ++i){
        cin>>item;
        nums.push_back(item);
    }
    Solution s1;
    s1.get_ans(nums);
}