#include<iostream>
#include<vector>

using namespace std;

class Solution{
private:
    void head_down(int i, int size, vector<int>& nums){
        while(i<size){
            int left = 2 * i + 1, right = 2 * i + 2;
            int max = i;
            if(left < size && nums[left] > nums[max]){
                max = left;
            }
            if(right < size && nums[right] > nums[max]){
                max = right;
            }
            if(max == i){
                break;
            }
            swap(nums[i], nums[max]);
            i = max;
        }
    }

    void maxHeapity(vector<int>& nums, int size){
        for(int i = size/2-1; i >= 0; i--){
            head_down(i, size, nums);
        }
    }
public:
    vector<int> heap_sort(vector<int>& nums){
        int n = nums.size();
        maxHeapity(nums, n);
        swap(nums[0], nums[n-1]);
        for(int i = n-2; i > 0; i--){
            n--;
            head_down(0, n, nums);
            swap(nums[0], nums[i]);
        }
        return nums;
    }
};

int main(){
    vector<int> nums = {5, 3, 1, 2};
    Solution s1;
    vector<int> res = s1.heap_sort(nums);
    for(int i : res){
        cout<<i<<"\t";
    }
}