#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points){
        if(points.size() == 1) return 1;
        sort(points.begin(), points.end(), cmp);
        int res = 1;
        int pos = points[0][1];
        for(int i = 1; i < points.size(); ++i){
            if(points[i][0] > pos){
                res++;
                pos = points[i][1];
            }
        }
        return res;
    }
};