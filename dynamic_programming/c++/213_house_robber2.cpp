#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/* 如何才能保证第一间房屋和最后一间房屋不同时偷窃呢？如果偷窃了第一间房屋，则不能偷窃最后一间房屋，因此偷窃房屋的范围是第一间房屋到最后第二间房屋；
如果偷窃了最后一间房屋，则不能偷窃第一间房屋，因此偷窃房屋的范围是第二间房屋到最后一间房屋。

假设数组 \textit{nums}nums 的长度为 nn。如果不偷窃最后一间房屋，则偷窃房屋的下标范围是 [0, n-2][0,n−2]；
如果不偷窃第一间房屋，则偷窃房屋的下标范围是 [1, n-1][1,n−1]。
在确定偷窃房屋的下标范围之后，即可用第 198 题的方法解决。对于两段下标范围分别计算可以偷窃到的最高总金额，其中的最大值即为在 nn 间房屋中可以偷窃到的最高总金额。

 */
class Solution{
public:
    int rob(vector<int>& nums){
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);

        int res1 = robRange(nums, 0, nums.size() - 2);
        int res2 = robRange(nums, 1, nums.size() - 1);
        return max(res1, res2); 
    }

    int robRange(vector<int>& nums, int start, int end){
        vector<int> dp(nums.size(), 0);
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);

        for(int i = start + 2; i <= end; ++i){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[end];

    }
};
