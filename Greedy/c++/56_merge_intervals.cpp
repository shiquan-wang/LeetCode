#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    // static bool cmp( const vector<int>&a, const vector<int>& b){
    //     if(a[1] == b[1]) return a[0] < b[0];
    //     return a[1] < b[1];
    // }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.size() == 0) return result;
        // 排序的参数使用了lamda表达式
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];});

        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (result.back()[1] >= intervals[i][0]) { // 合并区间
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};