#include<iostream>
#include<vector>
using namespace std;

class Soltuion{
public:
    void quick_sort(vector<int>& nums, int left, int right){
        if(left >= right) return;

        int pivot_index = rand() % (right - left) + left;
        int pivot = nums[pivot_index];

        int i = left, j = right;
        while(i < j){
            while(i < j && nums[i] <= pivot){
                ++i;
            }
            while ( i < j && nums[j] >= pivot)
            {
                --j;
            }
            if(i < j){
                swap(nums[i], nums[j]);
            }
        }
        quick_sort(nums, left, i-1);
        quick_sort(nums, i, right);
    }
};
int main(){
    Soltuion s1;
    vector<int> nums = {3, 2, 1, 2, 4 ,5 , 5, 6};
    s1.quick_sort(nums, 0, nums.size() - 1);
    for(int item: nums){
        cout<<item;
    }
}