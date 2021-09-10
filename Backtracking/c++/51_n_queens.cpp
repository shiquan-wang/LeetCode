#include<iostream>
#include<vector>

using namespace std;

class Solution{
private:
    vector<vector<string>> res;
    vector<string> path;
    bool is_vaild(int row, int col, vector<string>& chessboard, int n){
        int count = 0;
        for(int i = 0; i < row; ++i){//同一列
            if(chessboard[i][col] == 'Q'){
                return false;
            }
        }

        for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {//45度方向
            if (chessboard[i][j] == 'Q') {
             return false;
            }
        }
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {//135度方向
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
    void backtracking(int n, int row, vector<string>& chessboard){
        if(row == n){
            res.push_back(chessboard);
            return;
        }

        for(int col = 0; col < n; ++col){
            if(is_vaild(row, col, chessboard, n)){
                chessboard[row][col] = 'Q';
                backtracking(n, row + 1, chessboard);
                chessboard[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n){
        res.clear();
        vector<string> chessboard(n, string(n, '.'));
        backtracking(n, 0, chessboard);
        return res;
    }
};