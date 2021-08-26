#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution{
private:
    unordered_map<int, string> mp = {{2,"abc"}, {3,"def"}, {4,{"ghi"}}, {5,"jkl"}, {6,"mno"}, {7,"pqrs"}, {8,"tuv"}, {9,"wxyz"}};
    vector<string> res;
    string path;
    void backtracking(int index, string& digits){
        if(index == digits.size()){//index代表深度即当前已经取到的字母数量
            res.push_back(path);
            return;
        }

        int digit = digits[index] - '0';
        string letters = mp[digit];
        for(int i = 0; i < letters.size(); ++i){
            path.push_back(letters[i]);
            backtracking(index+1, digits);
            path.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits){
        res.clear();
        path.clear();
        if(digits.size() == 0){
            return res;
        }
        backtracking(0, digits);
        return res;

    }
};