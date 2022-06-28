#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    vector<int> subsort(vector<int>& array){
        vector<int> ans = {-1, -1};
        int n = array.size();

        int curr_min = INT_MAX;
        for(int i = n-1; i >=0; --i){//左边界是右边有比它小的元素
            if(array[i] > curr_min){
                ans[0] = i;
            }else{
                curr_min = min(curr_min, array[i]);
            }
        }

        int curr_max = INT_MIN;
        for(int i = 0; i < n; ++i){//右边界是左边有比它大的元素，从左到右，每个位置和从开头到i之间的最大值进行比较，如果比最大值小，那么当前节点就是右边界，一直向后遍历，寻找到最右的边界
            if(array[i] < curr_max){
                ans[1] = i;
            }else{
                curr_max = max(curr_max, array[i]);
            }
        }

        return ans;
    }
};