#include<iostream>
#include<vector>

using namespace std;

/* 
给定一个已按照 升序排列  的整数数组 numbers ，请你从数组中找出两个数满足相加之和等于目标数 target
(如果是无序数组，可以遍历第一遍使用哈希表存储数值，然后遍历第二遍，遍历至numbers[i]时， 判断target - numbers[i] 是否存在，存在即为结果)
 */
class Solution{
public:
    vector<int> twoSum(vector<int>& numsbers, int target){//常规思路，双层循环遍历数组，寻找答案. O(n^2)
        vector<int> res(2, -1);
        for(int i = 0; i < numsbers.size() - 1 && numsbers[i] <= target; ++i){
            for(int j = i+1; j < numsbers.size(); ++j){
                int temp = numsbers[i] + numsbers[j];
                if(temp == target){
                    res[0] = i; 
                    res[1] = j;
                }
            }
        }
        return res;
    }

    vector<int> twoSum2(vector<int>& numbers, int target){
        vector<int> res(2, -1);
        for(int i = 0, j = numbers.size()-1; i < j;){//双指针，O(n)
            if(numbers[i] + numbers[j] == target){
                res[0] = i; res[1] = j;
                break;
            }else if(numbers[i] + numbers[j] > target){
                j--;
            }else{
                i++;
            }
        }

        return res;
    }
};