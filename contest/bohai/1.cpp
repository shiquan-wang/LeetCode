#include<iostream>
#include<vector>

using namespace std;

class Solution{
private:
    vector<vector<int>> ans;
    vector<int> path;
public:
    void dfs(vector<vector<int>>& vec, int i, vector<vector<bool>>& vis){
        if(path.size() >= 4){
            if(path.size() == 4){
                ans.push_back(path);
            }
            return;
        }

        path.push_back(i);
        int j = 0;
        for(; j < vec.size(); ++i){
            if(vec[i][j] == 1 && vis[i][j] == false){
                vis[i][j] = true;
                dfs(vec, j, vis);
                vis[i][j] = false;
            }
        }
        path.pop_back();
    }
    void get_ans(vector<vector<int>>& vec){
        if(vec.size() < 3){
            cout<<"0";
            return;
        }
        if(vec.size() == 3){
            cout<<"6";
            return;
        }
        int count = 0;
        vector<vector<bool>> vis(vec.size(), vector<bool>(vec.size(), false));
        
        for(int i = 0; i < vec.size(); ++i){
            ans.clear();
            path.clear();
            dfs(vec, 0, vis);
            count += ans.size();
        }
        cout<<count;
    }
};
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> vec(n, vector<int>(n, 0));
    int a, b;
    for(int i = 0; i < m; ++i){
        cin>>a>>b;
        vec[a-1][b-1] = 1;
        vec[b-1][a-1] = 1;
    }
    Solution s1;
    s1.get_ans(vec);
}