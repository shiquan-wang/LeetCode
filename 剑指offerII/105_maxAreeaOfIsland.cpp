#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/* 
给定一个由 0 和 1 组成的非空二维数组 grid ，用来表示海洋岛屿地图。

一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

找到给定的二维数组中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。
思路：递归
登陆某个岛屿后，以此时位置为中心，向东西南北四个方向前进，如果某个方向前进后为水或者是已经探索过的地方则停止，逐步探索所有的位置。
小tip,将探索过的位置岛屿由1置为0，这样可以避免重复探索，而且不需要额外的数组来标志该位置是否已被探索。
 */
class Solution{
public:
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || i >= grid.size()){//下标越界
            return 0;  
        }
        if(j < 0 || j >= grid[0].size()){//下标越界
            return 0;
        }
        if(grid[i][j] == 0){//grid[i][j]是水
            return 0;
        }

        grid[i][j] = 0;//grid[i][j]是岛屿，area + 1, 将其转换为0，向四周扩展，
        return 1 + dfs(grid, i-1, j) + dfs(grid, i+1, j) + dfs(grid, i, j-1) + dfs(grid, i, j+1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid){
        int res = 0, area = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    area  = dfs(grid, i, j);
                    res = max(res, area);                                 
                }
            }
        }
        return res;
    }
};