#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/* 
给你一个下标从 0 开始的数组 nums ，该数组由 n 个正整数组成。
如果满足下述条件，则数组 nums 是一个 交替数组 ：
nums[i - 2] == nums[i] ，其中 2 <= i <= n - 1 。
nums[i - 1] != nums[i] ，其中 1 <= i <= n - 1 。
在一步 操作 中，你可以选择下标 i 并将 nums[i] 更改 为 任一 正整数。
返回使数组变成交替数组的 最少操作数 。
 */
/* 
思路： 遍历数组，统计奇数位和偶数位出现次数最多的前两个数字，将其他位数字变为出现次数最多的数字就是最少的操作次数，
特殊情况，奇数位和偶数位出现次数最多的数字相同，取多者，另一个位置取第二多的数字。
 */

class Solution{
public:
    int minimumOperations(vector<int> nums){

    }

    vector<int> countNums(vector<int> nums){
        
        unordered_map<int, int> up0, up1;
        for(int i = 0; i < nums.size(); i = i + 2){//统计奇数位每个数字出现的次数
            up0[nums[i]] ++;
        }
        for(int i = 1; i < nums.size(); i = i + 2){//统计偶数位每个数字出现的次数
            up1[nums[i]] ++;
        }

        unordered_map<int, int> :: iterator iter; //= up0.begin();

        int max1 = -1, max2 = -1;//记录迭代次数
        int count1 = 0, count2 = 0;//记录对应数字
        for(iter = up0.begin(); iter != up0.end(); iter++){
            if(iter->second > max1){
                max1 = iter->second;
                count1 = iter->first;
            }else if(iter->second>){
                
            }
        }
    }
};