#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;
/* 
给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素
 */
class Solution{
public:
    int singleNumber(vector<int>& nums){//时间复杂度O(N) 空间复杂度O(N)
    /* 
    使用哈希映射统计数组中每个元素的出现次数。对于哈希映射中的每个键值对，键表示一个元素，值表示其出现的次数。

    在统计完成后，我们遍历哈希映射即可找出只出现一次的元素。
     */
        vector<int> temp(nums.size(), 0);
        unordered_set<int> us(nums.size());
        unordered_map<int, int> up;
        for(int i = 0; i < nums.size(); ++i){
            up[nums[i]]++;
        }

        int ans = 0;
        /* for(auto [num, occ] : up){
            if(occ == 1){
                ans = num;
                break;
            }
        } */
        //unordered_map<int, int> :: iterator iter = up.begin();
        for(auto iter = up.begin(); iter != up.end(); ++iter){
            if(iter->second == 1){
                ans = iter->first;
                break;
            }
        }

        return ans;
    }
};