#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/* 
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组

思路：排序后，确定第一个数后，第二个和第三个数使用双指针的方法来求得

 */
class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size() - 2; ++i){
            if(nums[i] > 0) return ans;
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            vector<int> temp;
            int left = i+1, right = nums.size() - 1;
            while (left < right)
            {
                /* code */
                if(nums[i] + nums[left] + nums[right] == 0){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (left < right&& nums[left] == nums[left-1])
                    {
                        left++;
                    }
                    while (left < right&& nums[right] == nums[right+1])
                    {
                        right--;
                    }
                    left++;
                    right--;
                }else if(nums[i] + nums[left] + nums[right] > 0){
                    while (left < right&& nums[right] == nums[right+1])
                    {
                        right--;
                    }
                    right--;
                }
                else{
                    while (left < right&& nums[left] == nums[left-1])
                    {
                        left++;
                    }
                    left++;
                }
            }
            
        }
        return ans;
    }
};