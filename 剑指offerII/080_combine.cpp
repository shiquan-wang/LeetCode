#include<iostream>
#include<vector>

using namespace std;
/* 
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 */
class Solution{
private:
    vector<int> temp;
    vector<vector<int>> res;
public:
    void backtracking(int n, int k, int start_index){
        if(temp.size() == k){
            res.push_back(temp);
            return;
        }
        for(int i = start_index; i <= n-(k - temp.size()) + 1; ++i){//i<n-(k-path.size())+1 剪枝操作，当从i开始的数字个数不足k-path.size()个时，直接剪去这一分支的操作
            temp.push_back(i);
            backtracking(n, k, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k){
        temp.clear();
        res.clear();
        backtracking(n, k, 1);
        return res;
    }
};