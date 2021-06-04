#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    /* 从矩阵的左下角出发可以看做是一个二叉树，向上为左节点（小于根节点），向右为右节点（大于根节点），这样就可以进行类似二叉树的搜索 */
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        int r = matrix.size();
        int c = matrix[0].size();
        int i=r-1,j=0;
        while(i>-1 && j<c){
            if(matrix[i][j] == target){
                return true;
            }else if(matrix[i][j]<target){
                ++j;
            }else{
                --i;
            }
        }
        return false;
    }
};

int main(){
    vector<vector<int>> v(4,vector<int>(4));
}