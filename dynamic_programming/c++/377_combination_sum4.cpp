#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int combinationSum4(vector<int>& nums, int target){
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for(int j = 1; j <= target; ++j){
            for(int i = 0; i < nums.size(); ++i){
                if(j < nums[i] || dp[j] >= INTMAX_MAX - dp[j - nums[i]]) continue;
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp[target];
    }
};