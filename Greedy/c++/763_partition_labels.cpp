#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution{
private:
    // bool is_partition(string s, int left, int right){
    //     for(int i = left, j = right; i <= j; ++i, --j){
    //         if(s[i] != s[j]){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
public:
    vector<int> partitionLabels(const string& s){
        int hash[27] = {0};
        for(int i=0; i < s.size(); ++i){
            hash[s[i] -'a'] = i;
        }
        vector<int> res;
        int left = 0, right = 0;
        for(int i=0; i < s.size(); ++i){
            right = max(right, hash[s[i] - 'a']);
            if(i == right){
                res.push_back(right - left + 1);
                left = i+1;
            }
        }
        return res;
    }
};
