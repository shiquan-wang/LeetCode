#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/* 
给定一个二进制数组 nums , 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度
 */
class Solution{
public:
    int findMaxLength(vector<int>& nums){
        int res = 0;
        int count_0 = 0, count_1 = 0;
        
        for(int i = 0; i < nums.size(); ++i){
            unordered_map<int, int> up;
            for(int j = i-1; j >= 0; j = j-2){
                up[nums[j]]++;
                if(up[0] == up[1]){
                    res = res > (i - j + 1) ? res : (i-j+1);
                }
            }
        }

        return res;
    }

    int findMaxLength(vector<int>& nums){//前缀和 + 哈希表 // 数组不变而批量查询子数组的和 可以考虑前缀和
        unordered_map<int, int> map;
        int sum = 0, res = 0;

        map[0] = -1;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i] ? 1 : -1;
            if(map.find(sum) != map.end()){
                res = res > (i - map[sum]) ? res : (i - map[sum]) ;
            }else{
                map[sum] = i;
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {0, 1, 1};
    Solution s1;
    cout<<s1.findMaxLength(nums);
}