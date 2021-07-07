#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int lengthOfLIS(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n, 1);
        int max_len = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            max_len = max(max_len, dp[i]);
        }
        return max_len;
    }
};

int main(){
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    Solution s;
    cout<<s.lengthOfLIS(nums);
}