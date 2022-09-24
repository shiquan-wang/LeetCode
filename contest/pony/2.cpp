#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
private:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0,1}};
    vector<int> dir_map(char ch){
        switch (ch)
        {
        case '^':
            return dir[0];
            break;
        case 'v':
            return dir[1];
            break;
        case '<':
            return dir[2];
            break;
        case '>':
            return dir[3];
            break;
        default:
            return {};
            break;
        }
    }
public:
    int dfs(vector<vector<char>>& nums, vector<vector<bool>>& vis, int x, int y, vector<vector<int>>& paths){
        if(vis[x][y] == true){//遍历到已经遍历过的节点
            return 0;
        }
        vector<int> temp = dir_map(nums[x][y]);//获取方向
        int new_x = x + temp[0];
        int new_y = y + temp[1];
        vis[x][y] = true;
        if(new_x < 0 || new_x >= nums.size() || new_y < 0 || new_y >= nums[0].size()){//移动方向越界
            return 1;
        }
        // if(paths[new_x][new_y] != -1){
        //     return 1 + paths[new_x][new_y];
        // }
        return 1 + dfs(nums, vis, new_x, new_y, paths);
    }
    int scch(vector<vector<char>>& nums){
        int n = nums.size();
        int m = nums[0].size();
        vector<vector<int>> path(n, vector<int>(m, -1));
        int ans = -1;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                vector<vector<bool>> vis(n, vector<bool>(m, false));
                int temp_ans = dfs(nums, vis, i, j, path);
                path[i][j] = temp_ans;
                ans = max(ans, temp_ans);
                cout<<i<<" "<<j<<""<<temp_ans<<endl;
            }
        }
        return ans;
    }
};
int main(){
    vector<vector<char>> vec;
    vector<char> temp;
    int N, M;
    cin>>N>>M;
    char item;
    for(int i = 0; i < N; ++i){
        temp.clear();
        for(int j = 0; j < M; ++j){
            cin>>item;
            temp.push_back(item);
        }
        vec.push_back(temp);
    }
    
    Solution s1;
    int ans = s1.scch(vec);
    cout<<ans;
}