#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    bool canJump(vector<int>& nums){//每次取最大跳跃步数（取最大覆盖范围），整体最优解：最后得到整体最大覆盖范围，看是否能到终点
       int cover = 0;
       if(nums.size() == 1) return true;
       for(int i = 0; i <= cover; ++i){
           cover = max(i + nums[i], cover);
           if(cover >= nums.size()-1) return true;
       }
       return false;
    }
};