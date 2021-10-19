#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    bool canPartition(vector<int>& nums){
        int sum = 0;
        for(auto i : nums) sum += i;
        if(sum % 2 == 1) return false;
        int target = sum /2;
        vector<int> dp(10001, 0);

        for(int i = 1; i < nums.size(); ++i){
            for(int j = target; j >= nums[i]; --j){
                dp[j] = max(dp[j], dp[j-nums[i]] + nums[i]);
            }
        }

        if(dp[target] == target) return true;
        else return false;
    }
};

int main(){
    vector<int> nums = {1, 5, 11, 5};
    Solution s;
    bool res = s.canPartition(nums);
}