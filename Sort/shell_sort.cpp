#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    vector<int> shell_sort(vector<int>& nums){
        //先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，具体算法描述：(插入排序的高级版)
        //1, 将一个数组按照相同间隔h进行分组，每个小数组分别进行插入排序
        //2, 将间隔缩小，并继续排序，直至间隔为1
        //数学证明当 h = 3 * h + 1时， 希尔排序平均时间复杂度最优
        int h = (nums.size() - 1) / 3;
        int h = 1;
        while(h < nums.size() / 3){
            h = 3 * h + 1;
        }

        while (h > 0)
        {
            for(int i = h; i < n; ++i){
                int index = i - h, temp = nums[i];
                while (index >= 0 && nums[index] > temp)
                {
                    nums[index + h] = nums[index];
                    index -= h;
                }
                nums[index + h] = temp;                
            }
            h = h/3;
        }

        return nums;
        
    }
};