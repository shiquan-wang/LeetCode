#include<iostream>
#include<vector>
#include<string>

using namespace std;
/* 
正整数 n 代表生成括号的对数，请设计一个函数，用于能够生成所有可能的并且 有效的 括号组

思路1:回溯法
我们可以只在序列仍然保持有效时才添加‘(’ 或 ‘)’，而不是每次添加。我们可以通过跟踪到目前为止放置的左括号和右括号的数目来做到这一点，
如果左括号数量不大于 n，我们可以放一个左括号。如果右括号数量小于左括号的数量，我们可以放一个右括号。

 */
class Solution{
private:
    vector<string> res;
    string path;
public:
    void backtracking(int open, int close, int n){//0ms
        if(close > open){//终止条件，在回溯过程中提前结束异常分支, 相当于剪枝操作
            return;
        }
        if(path.size() == n*2){
            res.push_back(path);
            return;
        }

        if(open < n){
            path.push_back('(');
            open++;
            backtracking(open, close, n);
            open--;
            path.pop_back();
        }

        if(close < n){
            path.push_back(')');
            close++;
            backtracking(open, close, n);
            close--;
            path.pop_back();
        }
    }
    void backtracking2(int open, int close, int n){//4ms 
        if(path.size() == n*2){
            res.push_back(path);
            return;
        }

        if(open < n){
            path.push_back('(');
            open++;
            backtracking(open, close, n);
            open--;
            path.pop_back();
        }

        if(close < open){
            path.push_back(')');
            close++;
            backtracking(open, close, n);
            close--;
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n){
        res.clear();
        path.clear();
        backtracking(0, 0, n);
        return res;
    }
};