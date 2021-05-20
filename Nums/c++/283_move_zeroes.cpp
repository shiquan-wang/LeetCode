/* Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
 */
#include <iostream>
#include <vector>

using namespace std;

//思路：使用index来计算非零的个数，如果nums[i]非零，将其放在nums[index]的位置，++index,最后再将index至n的位置置零

class Solution{
    public:
    void moveZeroes(vector<int>& nums){
        int n = nums.size();
        int index = 0;
        for(int i = 0; i<n; ++i){
            if(nums[i] != 0){
                nums[index] = nums[i];
                ++index;
            }
        }
        for(; index<n; ++index){
            nums[index] = 0;
        }
    }
    void moveZeros(vector<int>& nums){
        int left = 0, right = 0;
        /* 左指针指向非零序列的下一个元素，如果右指针不为零，则交换左右指针对应数值，左指针右移指向非零序列下一个位置 ，右指针右移遍历下一个元素*/
        for(; right<nums.size();++right){
            if(nums[right] != 0){
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                left++;
            }
        }
    }
};

int main(){
    int a[] = {0,1,0,3,2};
    vector<int> nums;
    for(int i=0; i<5; ++i){
        nums.push_back(a[i]);
    }
    Solution s;
    s.moveZeroes(nums);
    vector<int> :: iterator it;
    for(it=nums.begin(); it!=nums.end(); ++it){
        cout<<*it<<endl;
    }
}