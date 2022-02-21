#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/* 
给定一个含有 n 个正整数的数组和一个正整数 target 。找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。
如果不存在符合条件的子数组，返回 0 。

基本思路：暴力循环，双层遍历O(n^2) 从每一个下标i开始寻找满足要求的子数组，记录长度与res进行比较取较小值。
滑动窗口：O(n), 左边界起始0，右边界起始也为0，右边界j向右走直到窗口内数值和sum >= target; 此时再移动左边界，使得窗口最小。在此期间更新res的值，当j遍历到最右边时遍历结束，
 */
class Solution{
public:
    int minSubArrayLen(int target, vector<int>& nums){
        if(nums.size() == 0) return 0;

        int res = INT_MAX;
        for(int i = 0; i < nums.size(); ++i){
            int temp = 0;
            for(int j = i; j < nums.size(); ++j){
                temp += nums[j];
                if(temp >= target){
                    res = min(res, j - i + 1);
                    break;
                }
            }
        }
        return res == INT_MAX ? 0 : res;
    }

    int minSubArrayLen2(int target, vector<int>& nums){
        int res = INT_MAX;
        int sum = 0;//滑动窗口数值之和
        int i = 0;//滑动窗口起始位置
        int subLength = 0;//滑动窗口的长度

        for(int j = 0; j < nums.size(); ++j){
            sum += nums[j];
            while (sum >= target)//注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
            {
                subLength = (j - i + 1);//取子序列的长度
                res = res < subLength ? res : subLength;
                sum -= nums[i]; ++i;//不断变更窗口的起始位置i
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};

int main(){
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    Solution s1;
    cout<<s1.minSubArrayLen2(7, nums);
}
