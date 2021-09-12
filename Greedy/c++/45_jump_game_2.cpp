#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    int jump1(vector<int>& nums){
        int n = nums.size();
        vector<int> dp = {n, 0};
        dp[0] = 1;
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < min(i + nums[i], n); ++j){
                if(dp[j] == 0){
                    dp[j] = dp[i] + 1;
                }else {
                    dp[j] = min(dp[j], dp[i] + 1);
                }
            }
        }
        return dp[n-1];
    }
    int jump(vector<int>& nums) {
        int curDistance = 0;    // 当前覆盖的最远距离下标
        int ans = 0;            // 记录走的最大步数
        int nextDistance = 0;   // 下一步覆盖的最远距离下标
        for (int i = 0; i < nums.size() - 1; i++) { // 注意这里是小于nums.size() - 1，这是关键所在
            nextDistance = max(nums[i] + i, nextDistance); // 更新下一步覆盖的最远距离下标
            if (i == curDistance) {                 // 遇到当前覆盖的最远距离下标
                curDistance = nextDistance;         // 更新当前覆盖的最远距离下标
                ans++;
            }
        }
        return ans;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {2, 3, 1, 1, 4};
    int n = s1.jump(nums);
    cout<<n;
}