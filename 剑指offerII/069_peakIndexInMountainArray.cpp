#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int peakIndexInMountainArray(vector<int>& arr){
        // if(arr.size() < 3) return 0;
        int max_index = 0;
        for(int i = 1; i < arr.size(); ++i){
            if(arr[i] < arr[i-1]){
               break;
            }
            max_index = i;
        }
        // if(max_index == )
        return max_index;
    }
};