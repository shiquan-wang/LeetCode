#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals){
        sort(intervals.begin(), intervals.end(), cmp);
        int res = 1;
        int pos = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i][0] >= pos){
                res++;
                pos = intervals[i][1];
            }
        }
        return intervals.size()-res;
    }
};