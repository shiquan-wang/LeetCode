#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/* 
给定一个由 不同 正整数组成的数组 nums ，和一个目标整数 target 。请从 nums 中找出并返回总和为 target 的元素组合的个数。数组中的数字可以在一次排列中出现任意次，但是顺序不同的序列被视作不同的组合。

思路：回溯法可以搜索所有可以的解，超时
思路二：动态规划，找的是排列数，完全背包
1，dp[i], 凑出总和为j的的排列数为dp[j]
2，递推关系，对于每一个nums[j],如果考虑将nums[j]作为总和为j的排列的最后一个元素,则dp[i] = dp[i - nums[j]],因此，遍历整个nums,计算所有的dp[i - nums[j]],
3，初始化，dp[0] = 1
4, 遍历顺序，求的是排列数，因此外层遍历背包，内层遍历物品
    原因举例，如果先遍历nums,那么dp[4]只能出现{1， 3}，不会出现{3, 1}的排列，因为nums在外层遍历，3只能出现在1的后面。
5， 举例推导dp数组
nums = {1, 2, 3} target = 4
dp数组：
dp[0] = 1, 
dp[1] = dp[0] = 1, {1}
dp[2] = dp[2 - nums[0]] + dp[2 - nums[1]] = dp[0] + dp[1] = 2, {2} {1, 1}
dp[3] = dp[3 - nums[0]] + dp[3 - nums[1]] + dp[3 - nums[2]] = dp[2] + dp[1] + dp[0] = 4, {2, 1} {1, 1, 1} {1, 2} {3}
dp[4] = dp[4 - nums[0]] + dp[4 - nums[1]] + dp[4 - nums[2]] + dp[4 - nums[3]] = dp[3] + dp[2] + dp[1] + dp[0] = 7, 
 */
class Solution{
public:
    int combinationSum4(vector<int>& nums, int target){
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for(int i = 1; i <= target; ++i){
            for(int j = 0; j < nums.size(); ++j){
                if(i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]]){
                    dp[i] += dp[i - nums[j]];
                }
            }
        }

        return dp[target];
    }
};