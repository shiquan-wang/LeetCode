#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/* 
给定一个三角形 triangle ，找出自顶向下的最小路径和。

每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。
输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
输出：11
解释：如下面简图所示：
   2
  3 4
 6 5 7
4 1 8 3
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
思路：动态规划
1， dp[i][j], 移动到(i,j)的最小路径和
2， dp[i][j]可能由(i-1, j-1)或(i-1, j)两个坐标移动而来，因此dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]
3,  初始化已经边界条件，dp[0][0] = triangle[0][0], 0 < i < m, dp[i][0]只能由经过dp[i-1][0]的结点路径得到，dp[i][0] = dp[i-1][0] + triangle[i][0]
4,  遍历顺序
5， 举例推导dp数组
 */
class Solution{
public:
    int minimumTotal(vector<vector<int>>& triangle){
        int m = triangle.size(), n = triangle[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = triangle[0][0];//初始化
        for(int i = 1; i < m; ++i){
            dp[i][0] = dp[i-1][0] + triangle[i][0];
        }

        for(int i = 1; i < m; ++i){//triangle 一共有m行
            for(int j = 1; j < i; ++j){//第i行有i个数据
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }

        int res = INT_MIN;
        for(auto item : dp[m]){
            if(res > item){
                res = item;
            }
        }
        return res;
    }
};

int main(){
    Solution s1;
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout<<s1.minimumTotal(triangle);
}