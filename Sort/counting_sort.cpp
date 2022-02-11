#include<iostream>
#include<vector>

//计数排序不是基于比较的排序算法，其核心在于将输入的数据值转化为键存储在额外开辟的数组空间中。 
//作为一种线性时间复杂度的排序，计数排序要求输入的数据必须是有确定范围的整数

//算法描述
//1, 找出待排序的数组中最大和最小的元素用来计算count数组的长度；
//2, 统计数组中每个值为i的元素出现的次数，存入数组count的[i-min]项；
//3, 反向填充目标数组：将元素 i+min 放在 nums[k] 中，每放一个元素就将C(i)减去1, k++, 直到C(i) == 0。

class Solution{
    std:: vector<int> counting_sort(std:: vector<int>& nums){
        int max  = nums[0], min = nums[0];
        for(int i : nums){//找到待排序数组中的最大最小值，确定计数数组的长度是多少
            if(i > max) max = i;
            if(i < min) min = i;
        }

        std:: vector<int> count(max - min + 1, 0);

        for(int i : nums){
            count[nums[i] - min] ++;//之所以不用count[nums[i]]来存储nums[i]出现的次数是因为{100000, 2000000}这种的数据会浪费大量的无用空间，所以使用count[nums[i] - min]来存储 nums[i] 的出现次数
        }

        int k = 0;
        for(int i = 0; i < count.size(); i++){//填充目标数组
            while(count[i] > 0){
                nums[k++] = min + i;
                count[i]--;
            }
        }

        return nums;
    }
};