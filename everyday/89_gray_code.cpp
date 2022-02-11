#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    vector<int> graycode(int n){
        vector<int> res;
        res.reserve(1 << n);
        res.push_back(0);
        for(int i = 0; i <= n; ++i){
            int m = res.size();
            for(int j = m-1; j >=0; --j){
                res.push_back(res[j] | (1 << (i-1)));
            }
        }
        return res;
    }
};