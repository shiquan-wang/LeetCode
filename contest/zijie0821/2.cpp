#include<iostream>
#include<vector>

using namespace std;

class Solution{
private:
    vector<vector<int>> add = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<int> switch_add(char ch){
        switch (ch)
        {
        case 'U': return add[0]; break;
        case 'D': return add[1]; break;
        case 'L': return add[2]; break;
        case 'R': return add[3]; break;
        default: break;
        }
    }
    
public:
    int nums_default(vector<vector<char>>& vec){
        vector<vector<int>> visited(vec.size(), vector<int>(vec[0].size(), -1));//-1未遍历，0不可到达，1可到达
        for(int i = 0; i < vec.size(); ++i){
            for(int j = 0; j < vec[0].size(); ++j){
                if(vec[i][j] == 'O'){
                    bfs(vec, visited, i, j);
                }
            }
            int ans = 0;
            for(auto v: visited){
                for(auto item: v){
                    if(item == 0){
                        ans++;
                    }
                }
            }
            return ans;
        }
    }
    void bfs(vector<vector<char>>&vec, vector<vector<int>>& visited, int i, int j){
        if(i<0 || i > vec.size()- 1 || j<0 || j > vec[0].size() - 1){
            return;
        }
        if(vec[i][j] == 'O'){
            visited[i][j] = 1;
        }else if(vec[i][j] == '.'){
            if(i > 0){
                if(visited[i-1][j] == 1){
                    visited[i][j] = 1;
                }
            }
            if(i < vec.size() - 1){
                if(visited[i+1][j] == 1){
                    visited[i][j] = 1;
                }
            }
            if(j < vec[0].size() - 1){
                if(visited[i][j+1] == 1){
                    visited[i][j] = 1;
                }
            }
            if(j > 0){
                if(visited[i][j-1] == 1){
                    visited[i][j] = 1;
                }
            }
            if(visited[i][j] == -1){
                visited[i][j] = 0;
            }
        }else{
            vector<int> ad = switch_add(vec[i][j]);
            int new_i = i + ad[0];
            int new_j = j + ad[1];
        }
    }
};

int main(){

}