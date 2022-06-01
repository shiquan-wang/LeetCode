/* 
给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）
思路：
将矩阵看成一个有向图，每个单元格对应图中的一个节点，如果相邻的两个单元格的值不相等，则在相邻的两个单元格之间存在一条从较小值指向较大值的有向边。问题转化成在有向图中寻找最长路径。

深度优先搜索是非常直观的方法。从一个单元格开始进行深度优先搜索，即可找到从该单元格开始的最长递增路径。对每个单元格分别进行深度优先搜索之后，即可得到矩阵中的最长递增路径的长度。

但是如果使用朴素深度优先搜索，时间复杂度是指数级，会超出时间限制，因此必须加以优化。

朴素深度优先搜索的时间复杂度过高的原因是进行了大量的重复计算，同一个单元格会被访问多次，每次访问都要重新计算。由于同一个单元格对应的最长递增路径的长度是固定不变的，因此可以使用记忆化的方法进行优化。
用矩阵memo 作为缓存矩阵，已经计算过的单元格的结果存储到缓存矩阵中。

使用记忆化深度优先搜索，当访问到一个单元格 (i,j) 时，如果 memo[i][j] ！=0，说明该单元格的结果已经计算过，则直接从缓存中读取结果，如果memo[i][j]=0，说明该单元格的结果尚未被计算过，则进行搜索，
并将计算得到的结果存入缓存中。

遍历完矩阵中的所有单元格之后，即可得到矩阵中的最长递增路径的长度。


 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
private:
    static constexpr int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    // 我们可以为const整型的静态数据成员提供类内初始值。constexpr的静态成员必须提供类内初始值。

    // 一般的static数据成员只能在类内声明，在类外定义和初始化。

    /* 
    static const数据成员可以在类内声明，在类外定义和初始化。在类内声明时，static const数据成员还未初始化，不算真正的const。
    static const整型数据成员可以在类内声明和初始化，在类外定义。在类内声明和初始化时，static const数据成员是真正的const。
    若编译时static const数据成员可用它的值替代（如表示数组个数等），它可以不需要定义。若不能替代（如作为参数等），必须含有一条定义语句。建议不管是否可替代都在类外定义一次。
    若static const数据成员不是整型（bool、char、int、short、long等），则不能在类内初始化。
     */

    /* 
    static constexpr数据成员必须在类内声明和初始化。在类内声明和初始化时，static constexpr数据成员是真正的const。
    若编译时static constexpr数据成员可用它的值替代（如表示数组个数等），它可以不需要定义。若不能替代（如作为参数等），必须含有一条定义语句。建议不管是否可替代都在类外定义一次。
    若static constexpr数据成员即使不是整型，也可进行类内初始化时。
     */
    int rows, columns;
public:
    int longestIncreasingPath(vector<vector<int>>& martix){
        if(martix.size() == 0 || martix[0].size() == 0){
            return 0;
        }

        rows = martix.size();
        columns = martix[0].size();
        auto memo = vector<vector<int>>(rows, vector<int>(columns, 0));
        int ans = 0;
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < columns; ++j){
                ans = max(ans, dfs(martix, i, j, memo));
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& martix, int row, int column, vector<vector<int>> memo){
        if(memo[row][column] != 0){
            return memo[row][column];
        }

        ++memo[row][column];
        for(int i = 0; i < 4; ++i){
            int newRow = row + dir[i][0], newColumn = column + dir[i][1];
            if(newRow >= 0 && newRow < rows && newColumn >= 0 && newColumn < columns && martix[newRow][newColumn] > martix[row][column]){
                memo[row][column] = max(memo[row][column], dfs(martix, newRow, newColumn, memo) + 1);
            }
        }
        return memo[row][column];
    }
};

