#include <iostream>
#include <vector>

using namespace std;

class Solution{
    /* 遍历数组nums,temp[nums-1]++, 遍历temp,temp[i] == 2的i+1就是出现两次的数，temp[i]==0的i+1就是没有出现的数 */
    public:
    vector<int> findErrorNums(vector<int>& nums){
        vector<int> res(2);
        vector<int> temp(nums.size(), 0);
        for(int i = 0; i<nums.size(); ++i){
            temp[nums[i]-1]++;
        }
        
        for(int i = 0; i<temp.size(); ++i){
            if(temp[i] == 2){
                 res[0] = i+1;
            }
           if(temp[i] == 0){
                res[1] = i+1;
           }
        }
        return res;
    }
};

int main(){
    vector<int> v(4,0);
    v[0] = 1; v[1]=2;v[2]=2;v[3]=4;
    Solution s;
    vector<int> res(2);
    res = s.findErrorNums(v);
}