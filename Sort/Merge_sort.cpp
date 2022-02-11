#include<iostream>
#include<vector>

using namespace std;

//时间复杂度O(nlogn) 稳定的排序
//分治法的典型应用，
//算法描述：
//把数组从中间划分为两个子数组，一直递归地把子数组划分成更小的数组，直到子数组里面只有一个元素的时候开始排序。
//排序的方法就是按照大小顺序合并两个元素。接着依次按照递归的顺序返回，不断合并排好序的数组，直到把整个数组排好序。
class Solution{
public:
    void mergesort(vector<int>& nums, int left, int right, vector<int>& ans){
        if(left >= right){
            return;
        }

        int mid = (left + right) / 2;
        mergesort(nums, left, mid);
        mergesort(nums, mid + 1, rihgt);
        
        return merge(nums, left, right, ans);
    }
    void merge(vector<int>& nums, int left, int right, vector<int>& ans){
        int mid = (right - left) / 2 + left;
        int i = left, j = mid + 1, k = 0;
        while (i <= mid && j <= right)
        {
            if(nums[i] <= nums[j]){
                ans[k++] = nums[i++];
            }else{
                ans[k++] = nums[j++];
            }
        }
        while(j <= right){
            ans[k++] = nums[j++];
        }
        for(int i = left; i <= right; i++){
            nums[i] = ans[i - left];
        }       
    }
};