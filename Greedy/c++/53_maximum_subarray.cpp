#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int maxSubArray(vector<int>& nums){
        int res = 0,max_subarray = INT_MIN;
        for(int i = 0; i < nums.size(); ++i){
            res += nums[i];
            if(res > max_subarray){
                max_subarray = res;
            }
            if(res < 0){
                res = 0;
            }
        }
        return max_subarray;
    }
};