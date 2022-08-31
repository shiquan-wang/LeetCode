#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class Solution{
private:
    vector<vector<int>> add = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    vector<int> fangxiang(char ch){
        if(ch == 'W'){
            return add[0];
        }
        if(ch == 'S'){
            return add[1];
        }
        if(ch == 'A'){
            return add[2];
        }
        if(ch == 'D'){
            return add[3];
        }
        return {};
    }
public:
    void dasao(int n, int m, string str){
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = n*m-1;
        int x = 0, y = 0, i = 0;
        vis[0][0] = 1;
        for(; i < str.size(); ++i){
            char ch = str[i];
            vector<int> temp = fangxiang(ch);
            int dx = temp[0], dy = temp[1];
            x += dx;
            y += dy;
            if(vis[x][y] == 0){
                ans--;
                vis[x][y] = 1;
            }
            if(ans == 0){
                break;
            }
        }
        if(ans == 0){
            // return {true, i+1};
            cout<<"Yes"<<endl<<i+1<<endl;
        }else{
            // return {false, ans};
            cout<<"No"<<endl<<ans<<endl;
        }
    }
};

int main(){
    int n, m, k;
    string str;
    cin>>n>>m>>k>>str;
    Solution s1;
    s1.dasao(n, m, str);
    return 0;
}