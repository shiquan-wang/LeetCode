/* 
给你一个整数数组 nums ，请计算数组的 中心下标 。

数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。

如果中心下标位于数组最左端，那么左侧数之和视为 0 ，因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用。

如果数组有多个中心下标，应该返回 最靠近左边 的那一个。如果数组不存在中心下标，返回 -1 

输入：nums = [1, 7, 3, 6, 5, 6]
输出：3
解释：
中心下标是 3 。
左侧数之和 sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11 ，
右侧数之和 sum = nums[4] + nums[5] = 5 + 6 = 11 ，二者相等。

思路：1 暴力循环超时
2 前缀和 记数组的全部元素之和为 total，当遍历到第 i个元素时，设其左侧元素之和为sum，则其右侧元素之和为total− nums[i] −sum。
左右侧元素相等即为sum=total−nums [i] −sum，即2×sum+nums[i]=total。
当中心索引左侧或右侧没有元素时，即为零个项相加，这在数学上称作「空和」empty sum。在程序设计中我们约定「空和是零」

 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
public:
    int pivotIndex(vector<int>& nums){
        int total = 0;
        for(int i : nums){//计算total值
            total += i;
        }

        int index = -1, sum = 0;
        //unordered_map<int,int> map;

        for(int i = 0; i < nums.size(); ++i){
            if(2 * sum + nums[i] == total){
                index = i;
                break;
            }
            sum += nums[i];
        }
        return index;
    }
};