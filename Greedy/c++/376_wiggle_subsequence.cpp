#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int wiggleMaxLength(vector<int>& nums){
        int n = nums.size();
        if(n<2) return n;
        int prediff = 0, curdiff =0, res = 1;
        for(int i = 0; i < n-1; ++i){
            curdiff = nums[i+1] - nums[i];
            if((curdiff > 0 && prediff <= 0) || (curdiff < 0 && prediff >= 0)){
                res++; prediff = curdiff;
            }
        }
        return res;
    }
};