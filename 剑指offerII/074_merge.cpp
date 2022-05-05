#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/* 
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。

*/
class Solution{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for(int i = 0; i < intervals.size(); ++i){
            int l = intervals[i][0], r = intervals[i][1];
            if(!merged.size() || merged.back()[1] < l){
                merged.push_back({l, r});
            }else{
                merged.back()[1] = max(merged.back()[1], r);
            }
        }
        return merged;
    }
};