#include<iostream>
#include<vector>

using namespace std;

class Solution{
private:
    vector<vector<string>> res;
    vector<string> path;
    bool is_palindrome(const string& s, int start_index, int end){
        for(int i = start_index, j = end; i < j; i++, j--){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }
    void backtracking(const string& s, int start_index){
        if(start_index >= s.size()){
            res.push_back(path);
            return;
        }

        for(int i = start_index; i < s.size(); i++){
            if(is_palindrome(s, start_index, i)){
                string str = s.substr(start_index, i - start_index + 1);
                path.push_back(str);
            }else{
                continue;
            }
            backtracking(s, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s){
        res.clear();
        path.clear();
        backtracking(s, 0);
        return res;
    }
};

int main(){
    string s = "aab";
    Solution s1;
    vector<vector<string>> res = s1.partition(s);
}