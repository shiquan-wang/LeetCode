#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Soltuion{
public:
    vector<int> quick_sort(vector<int>& nums, int left, int right){
        if(left >= right) return nums;

        int pivot_index = rand() % (right - left) + left;
        int pivot = nums[pivot_index];

        int i = left, j = right;
        while(i < j){
            while (nums[i] < pivot)
            {
                i++;
            }
            while(nums[j] > pivot){
                j--;
            }
            if(i < j){
                swap(nums[i], nums[j]);
            }
            
        }
        quick_sort(nums, left, j);
        quick_sort(nums, j+1, right);
        return nums;
    }

    
};