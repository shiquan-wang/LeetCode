#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    int candy(vector<int>& ratings){
        vector<int> nums(ratings.size(), 1);
        for(int i = 1; i < ratings.size(); ++i){
            if(ratings[i] >ratings[i-1]){
                nums[i] = nums[i-1] + 1;
            }
        }
        for(int i = ratings.size()-2; i >=0; --i){
            if(ratings[i] > ratings[i+1]){
                nums[i] = max(nums[i], nums[i+1] + 1);
            }
        }
        int res = 0;
        for (auto i : nums){
            res += i;
        }
        return res;
    }
};