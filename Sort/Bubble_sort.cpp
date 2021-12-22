#include<iostream>
#include<vector>
#include<time.h>
using namespace std;

class Solution{
public:
//冒泡排序，
//从开始比较相邻的元素。如果第一个比第二个大，就交换它们两个；
//对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对，这样在最后的元素应该会是最大的数；
//针对所有的元素重复以上的步骤，除了最后一个；
//重复步骤1~3，直到排序完成。
//初始：3, 5, 2, 4, 1
//第一次冒泡：3, 5, 2, 4, 1     3, 2, 5, 4, 1       3, 2, 4, 5, 1       3, 2, 4, 1, 5 
//第二次冒泡：2, 3, 4, 1, 5     2, 3, 4, 1, 5       2, 3, 1, 4, 5       
//第三次冒泡：2, 3, 1, 4, 5     2, 1, 3, 4, 5
//第四次冒泡：1, 2, 3, 4, 5
//
    vector<int> bubble_sort(vector<int>& nums){
        for(int i = 0; i < nums.size() - 1; ++i){//最大的遍历次数
            for(int j = 1; j < nums.size() - i; ++j){
                if(nums[j] < nums[j-1]){
                    swap(nums[j], nums[j-1]);
                }
            }
        }
        return nums;
        //时间复杂度 O(n^2)
    }

    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }

    vector<int> bubble_sort2(vector<int>& nums){//优化
        //使用flag位来表示本次冒泡过程中是否发生交换，如果没有那么说明数组已经有序了，直接终止排序过程, 可以减少时间复杂度
        bool flag = false;
        for(int i = 0; i < nums.size() - 1; ++i){//最大的遍历次数
            flag = false;
            for(int j = 1; j < nums.size() - i; ++j){
                if(nums[j] < nums[j-1]){
                    swap(nums[j], nums[j-1]);
                    flag = true;//发生交换，则数组未有序，
                }
            }
            if(flag == false) break;
        }
        return nums;
        //时间复杂度 O(n^2)
    }

};

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    Solution s1;
    clock_t start_time, end_time;
    start_time = clock();
    vector<int> res = s1.bubble_sort2(nums);
    end_time = clock();
    cout<<(double)(end_time - start_time) / CLOCKS_PER_SEC<<"\n";
    start_time = clock();
    vector<int> res2 = s1.bubble_sort(nums);
    end_time = clock();
    cout<<(double)(end_time - start_time) / CLOCKS_PER_SEC<<"\n";
    // for(int i : res){
    //     cout<<i<<"\t";
    // }
}