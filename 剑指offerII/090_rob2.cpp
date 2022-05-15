#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/* 
一个专业的小偷，计划偷窃一个环形街道上沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

给定一个代表每个房屋存放金额的非负整数数组 nums ，请计算 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。

和089的区别在于首尾两个元素连接起来了，
    因此可以考虑两种情况，
    第一：考虑偷盗第一间房屋，不考虑最后一间房屋
    第二：考虑偷盗最后一间房屋，不考虑第一间房屋
最后，取两种情况中的最大值即可

计算方法同089
1,dp[i]代表考虑前面i个房间可以偷盗到的最高金额
2,dp[i] = max(dp[i-1], dp[i-2] + nums[i]), 当i = nums.size() - 1,

 */
class Solution{
public:
    int rob(vector<int>& nums){
        int length = nums.size();
        if(length == 1){
            return nums[0];
        }else if(length == 2){
            return max(nums[0], nums[1]);
        }
        return max(rob_range(nums, 0, length - 2), rob_range(nums, 1, length - 1));

    }

    int rob_range(vector<int>& nums, int start, int end){
        int first = nums[start];
        int second = max(nums[start], nums[start + 1]);

        for(int i = start + 2; i <= end; ++i){
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }
};