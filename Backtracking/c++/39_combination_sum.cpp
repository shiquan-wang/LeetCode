#include<iostream>
#include<vector>

using namespace std;

class Solution{
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& candiates, int target, int sum, int start_index){//一个集合求组合问题需要start_index，如果是多个集合来求组合问题就不用了，一个集合可能会出现重复组合
        if(sum >= target){//终止条件
            if(sum == target){
                res.push_back(path);
            }
            return;
        }

        for(int i = start_index; i < candiates.size(); ++i){
            sum += candiates[i];
            path.push_back(candiates[i]);
            backtracking(candiates, target, sum, i);//关键点:不用start_index+1了，表示可以重复读取当前的数
            path.pop_back();
            sum -= candiates[i];
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        res.clear();
        path.clear();
        backtracking(candidates, target, 0, 0);
        return res;
    }
};