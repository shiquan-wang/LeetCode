#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int lengthOfLIS(vector<int>& nums){
        if(nums.size() == 1) return 1;

        vector<int> dp(nums.size(), 1); int res = 0;
        //dp[i] 从下标0 到 下标i 的最长递增子序列
        //dp[0] = 1;
        for(int i = 1; i < nums.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if(dp[i] > res) res = dp[i];
        }

        return res;
    }
};

int main(){
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    Solution s;
    cout<<s.lengthOfLIS(nums);
}