#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
private:
    vector<vector<int>> res;
    vector<int> path;
    int path_count;
public:
    void backtracking(vector<int>& candidates, int target, int start_index, int path_count){
        if(path_count >= target){
            if(path_count == target){
                res.push_back(path);
            }
            //start_index += 1;
            return;
        }
        for(int i = start_index;  i < candidates.size()&&candidates[i] + path_count <= target; ++i){
            path.push_back(candidates[i]);
            path_count += candidates[i];
            backtracking(candidates, target, i, path_count);
            path_count -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        path.clear();
        res.clear();
        path_count = 0;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, path_count);
        return res;
    }
};