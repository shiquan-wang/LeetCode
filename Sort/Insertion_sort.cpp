#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    vector<int> insertion_sort(vector<int>& nums){
        //工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
        //一般来说，插入排序都采用in-place在数组上实现。具体算法描述如下：
        //1, 从第一个元素开始，该元素可以认为已经被排序；
        //2, 取出下一个元素，在已经排序的元素序列中从后向前扫描；
        //3, 如果该元素（已排序）大于新元素，将该元素移到下一位置；
        //4, 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
        //5, 将新元素插入到该位置后；
        //重复步骤2~5。
        //初始顺序： 2, 1, 5, 4, 3
        //第一次 1, 2, 5, 4, 3
        //第二次 1, 2, 5, 4, 3
        //第三次 1, 2, 4, 5, 3
        //第四次 1, 2, 3, 4, 5
        for(int i = 1; i < nums.size(); ++i){//每次向有序区插入一个元素，共插入n-1次
            int index = i, temp = nums[i];
            for(int j = i-1; j >= 0; --j){//从后向前遍历有序区，将比nums[i]大的元素往后移
                if(nums[j] >= temp){
                    nums[j+1] = nums[j];
                    index = j;//记录nums[i]应该插入的下标
                }else{//记录nums[i]应该插入的下标 
                    index = j + 1;
                    break;
                }
            }
            nums[index] = temp;
            // for(int i : nums){
            //     cout<<i<<"\t";
            // }
            // cout<<"\n";
        }
        return nums;
        //时间复杂度O(n^2)
    }
    vector<int> insrtion(vector<int>& nums){
        for(int i = 1; i < nums.size(); ++i){
            int index = i - 1, temp = nums[i];
            while(index >= 0 && nums[index] > temp){//从后向前遍历有序区，将比nums[i]大的元素往后移 记录nums[i]应该插入的下标
                nums[index + 1] = nums[index];
                index--;
            }
            nums[index + 1] = temp;
        }
        return nums;
    }
};

int main(){
    vector<int> nums = {2, 1, 3, 5, 4};
    Solution s1;
    vector<int> res = s1.insertion_sort(nums);
    for(int i : res){
        cout<<i<<"\t";
    }
}