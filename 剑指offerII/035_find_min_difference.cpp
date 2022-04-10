#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution{
private:
    int get_minutes(string a){
        return ((int(a[0]) * 10 + int(a[1])) * 60 + (int(a[3]) * 10 + int(a[4])));
    }
public:
    int findMinDifference(vector<string>& timePoints){
        //鸽巢原理： 一共有24*60 = 1440个不同的时间，如果timePoints的长度超过1440,那么肯定有两个相同的时间，此时可以直接返回0
        if(timePoints.size() > 1440) return 0;
        
        sort(timePoints.begin(), timePoints.end());


        int ans = INT_MAX;
        for(int i = 0, j = 1; i < timePoints.size() - 1; ++i, ++j){//顺序遍历，计算两两之间的时间差
            int temp_m = get_minutes(timePoints[j]) - get_minutes(timePoints[i]);
            ans = min(ans, temp_m);
        }

        ans = min(ans, get_minutes(timePoints[0]) - get_minutes(timePoints[timePoints.size() - 1]) + 1440);//首尾时间差
        return ans;
    }
};