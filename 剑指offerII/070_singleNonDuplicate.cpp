#include<iostream>
#include<vector>

using namespace std;
/* 
给定一个只包含整数的有序数组 nums ，每个元素都会出现两次，唯有一个数只会出现一次，请找出这个唯一的数字。
思路：
异或，把数组中所有元素异或起来，最后剩下的就是只出现一次的数字O(N)
二分查找，
假设只出现一次的元素位于下标 x，由于其余每个元素都出现两次，因此下标 x 的左边和右边都有偶数个元素，数组的长度是奇数。
由于数组是有序的，因此数组中相同的元素一定相邻。对于下标 x 左边的下标 y，如果 nums[y]=nums[y+1]，则 y 一定是偶数；对于下标 x 右边的下标 z，
如果 nums[z]=nums[z+1]，则 z 一定是奇数。由于下标 x 是相同元素的开始下标的奇偶性的分界，因此可以使用二分查找的方法寻找下标 x。

初始时，二分查找的左边界是 0，右边界是数组的最大下标。每次取左右边界的平均值 mid 作为待判断的下标，根据 mid 的奇偶性决定和左边或右边的相邻元素比较：

如果 mid 是偶数，则比较 nums[mid] 和 nums[mid+1] 是否相等；

如果 mid 是奇数，则比较 nums[mid−1] 和 nums[mid] 是否相等。

如果上述比较相邻元素的结果是相等，则 mid<x，调整左边界，否则mid≥x，调整右边界。调整边界之后继续二分查找，直到确定下标 x 的值。

得到下标 xx 的值之后，\textit{nums}[x]nums[x] 即为只出现一次的元素。

有序数组应该首先考虑二分，相同元素是成对出现的，我们要找的是第一个不成对的元素。这里可以用一个异或的技巧来找到同一对元素：
    若mid为偶数，则mid ^ 1为奇数，是当前元素对的前一个元素；
    若mid为奇数，则mid ^ 1为偶数，是当前元素对的后一个元素。
 */
class Solution{
public:
    int singleNonDuplicate(vector<int>& nums){
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = (right - left) / 2 + left;//等价于(left + right) /  2，防止int溢出;
            if(nums[mid] == nums[mid^1]){
                left = mid +1;
            }else{
                right = mid;
            }
        }
        return nums[left];
    }
};