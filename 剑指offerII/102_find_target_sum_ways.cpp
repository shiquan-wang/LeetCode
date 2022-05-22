/* 
给定一个正整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

思路一：回溯法
对于所有可能性的问题，使用回溯法可以找到所有可行解。

思路二：动态规划
 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
private:
    int sum;
    int res;
public:
    void backtracking(vector<int>& nums, int target, int index){
        if(index == nums.size()){
            if(sum == target){
                res ++;
            }
            return;
        }

        sum += nums[index];
        backtracking(nums, target, index + 1);
        sum -= nums[index];
            
        sum -= nums[index];
        backtracking(nums, target, index + 1);
        sum += nums[index];
    }

    int findTargetSumWays(vector<int>& nums, int target){
        sum = 0;
        res = 0;
        backtracking(nums, target, 0);
        return res;
    }
};