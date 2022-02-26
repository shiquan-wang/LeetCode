#include<iostream>
#include<vector>

using namespace std;

/* 
给定一个正整数数组 nums和整数 k ，请找出该数组内乘积小于 k 的连续的子数组的个数。
思路类似于008，使用滑动窗口来找到一个满足乘积小于k的子数组，然后子数组中的每个组合都是满足条件的解
*/

class Solution{
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k){
        if(k <= 1) return 0;
        int res = 0;
        int temp = 1;
        int left = 0;
        for(int right = 0; right < nums.size(); ++right){
            temp *= nums[right];//计算累积
            while (left <= right && temp >= k)
            {
                temp /= nums[left++];
            }
            res += right >= left ? right - left + 1 : 0;
        }
        return res;
    }
};

int main(){
    vector<int> nums = {10, 5, 2, 6};
    Solution s1;
    cout<<s1.numSubarrayProductLessThanK(nums, 100);
}