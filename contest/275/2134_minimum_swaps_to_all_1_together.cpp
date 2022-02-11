#include<iostream>
#include<vector>

using namespace std;
//思路：
//统计数组中1的总个数，
//使用滑动窗口，统计窗口内0的个数即为需要交换的次数
//最小的即为结果
class Soltion{
public:
    int minSwaps(vector<int>& nums){
        int n = nums.size();
        int count_one = 0;
        for(int i = 0; i < n; ++i){//统计1的个数
            if(nums[i] == 1){
                count_one++;
            }
        }
        int res = INT_MAX;
        for(int i = 0; i < n; ++i){//滑动窗口统计交换次数，窗口大小为count_one
            int swap_num = 0;
            for(int j = 0; j < count_one; ++j){
                if(nums[(i+j) % n] == 0){
                    swap_num++;
                }
            }
            if(swap_num < res){
                res = swap_num;
            }
        }

        return res;
    }
};