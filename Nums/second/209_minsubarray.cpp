#include<iostream>
#include<vector>

using namespace std;
/* 
给定一个含有 n 个正整数的数组和一个正整数 target 。
找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

方法一：暴力搜索，每次确定起始下标i,逐次遍历结束下标j，记录以i开始的最短子数组长度，时间复杂度O(n^2)
方法二：因为数组内全部是整数，所以可以使用前缀和，而且前缀和都是递增的。以i开始的起始下标确定后，利用二分搜索的方法寻找到第一个前缀和大于sum(i)+target的下标j,此时长度为j - i + 1;
方法三：滑动窗口,前面两种方法都是确定起始位置，然后再确定结束位置。使用滑动窗口先确定子数组的结束位置，

定义两个指针 start 和 end 分别表示子数组（滑动窗口窗口）的开始位置和结束位置，
维护变量 sum 存储子数组中的元素和（即从 nums[start] 到nums[end] 的元素和）。
初始状态下，start 和 end 都指向下标 0，sum 的值为 0。
每一轮迭代，将 nums[end] 加到 sum，如果 sum≥s，
则更新子数组的最小长度（此时子数组的长度是end−start+1），然后将 nums[start] 从sum 中减去并将 start 右移，直到 sum<s，在此过程中同样更新子数组的最小长度。在每一轮迭代的最后，将end 右移。
 */
class Solution{
public:
    int minSubArrayLen(int target, vector<int>& nums){
        int res = INT_MAX;
        int i = 0;
        int sum = 0;
        int subLength = 0;
        for(int j = 0; j < nums.size(); ++j){
            sum += nums[j];
            while (sum >= target)
            {
                /* code */
                subLength = j - i + 1;
                res = res < subLength ? res : subLength;
                sum -= nums[i];
                i++;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};