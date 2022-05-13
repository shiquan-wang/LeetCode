#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/* 
一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响小偷偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组 nums ，请计算 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
思路：动态规划
1，dp[i][0] 代表偷盗至第i间房屋可以偷到的最高金额,其中dp[i][0]代表偷第i间房的现金可以达到的最大金额，dp[i][1]代表不偷盗第i间房可以达到的最大金额
2，dp[i][0] = dp[i-1][1] + nums[i], dp[i][1] = dp[i-1][0]
3, 初始化，dp[0][0] = nums[0] dp[0][1] = 0
4, 遍历顺讯， i=1, i< nums.size(); ++i
5, 推导dp数组

当遇到{2， 1， 1，2}时出现错误
修改dp数组定义：dp[i] 为从0到i的房屋最多可以偷窃的金额dp[i],重点在于考虑，考虑并不一定要偷，
dp[i] = max(dp[i-1], dp[i-2] + nums[i])
 */
class Solution{
private:

public:
    int rob1(vector<int>& nums){
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
        dp[0][0] = nums[0], dp[0][1] = 0;
        for(int i = 1; i < nums.size(); ++i){
            dp[i][0] = dp[i-1][1] + nums[i];
            dp[i][1] = dp[i-1][0];
        }

        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }
    int rob(vector<int>& nums){
        
        if(nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); ++i){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }

        return dp[nums.size() - 1];
    }
};

int main(){
    vector<int> nums = {1, 2, 3, 1};
    Solution s1;
    cout<<s1.rob(nums);
}