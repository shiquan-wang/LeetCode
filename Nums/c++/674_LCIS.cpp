#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int findLengthOfLCIS(vector<int>& nums){
        //dp[i] 为以nums[i]结尾 的最长连续递增子序列长度
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxLen = 1;
        for(int i = 1; i < n; ++i){
            if(nums[i] > nums[i-1]){
                dp[i] = dp[i-1] + 1;
            }else{
                dp[i] = 1;
            }
            if(dp[i] > maxLen){
                maxLen = dp[i];
            }
        }
        return maxLen;
    }
};

int main(){
    vector<int> nums = {1, 3, 5, 4, 7};
    Solution s;
    cout<<s.findLengthOfLCIS(nums);
}