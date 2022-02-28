#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
/* 
给你一个整数数组 nums 和一个整数 k ，请你统计并返回该数组中和为 k 的连续子数组的个数。

初步思路：使用双指针（滑动窗口），结果发现[-1, -1, 1], k = 0,时出错，后发现不能使用该方法，
因为为什么这题不可以用双指针/滑动窗口：因为nums[i]可以小于0，也就是说右指针i向后移1位不能保证区间会增大，
左指针j向后移1位也不能保证区间和会减小。给定j，i的位置没有二段性。


 */
using namespace std;

class Solution{
public:
    int subarraySum(vector<int>& nums, int k){//只有当nums中的所有元素均为正整数时才可以使用该方法
        int n = nums.size();
        
        int left = 0, right = 0;
        int sum = 0;
        int res = 0;
        for(; right < n; ++right){
            sum += nums[right];
            while(sum > k && left < right){
                sum -= nums[left++];
            }
            if(sum == k){
                res++;
                for(int i = left; i <= right; ++i){
                    cout<<nums[i]<<" ";
                }
                cout<<endl;
            }
        }

        return res;
    }
    int subarraySum2(vector<int>&nums, int k){//暴力循环，以下标i为结束点，向前遍历直到sum等于k或者遍历至数组的首位时停止，此时找到了以nums[i]为结尾的一个符合要求的子数组。
        int count = 0;
        for(int start = 0; start < nums.size(); ++start){
            int sum = 0;
            for(int end = start; end >= 0; --end){
                sum += nums[end];
                if(sum == k){
                    count++;
                }
            }
        }
        return count;
    }

    int subarraySum3(vector<int>& nums, int k){//哈希表 + 前缀和
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for(auto& x : nums){
            pre += x;
            if(mp.find(pre - k) != mp.end()){
                count += mp[pre - k];
            } 
            mp[pre]++;
        }
        return count;
    }
};

int main(){
    vector<int> nums = {1, 2, 3};
    Solution s1;
    cout<<s1.subarraySum(nums, 3);
}