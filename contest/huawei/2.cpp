#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
private:
    vector<vector<int>> dir1 = {{-1, 0}, {1, 0}, {0, -1}, {0,1}};
    vector<vector<int>> dir2 = {{-1, 2}, {-2, 1}, {1, 2}, {2, 1}, {-1, -2}, {-2, -1}, {1, -2}, {2, -1}};
public:
    pair<bool, int> dfs(vector<vector<char>>& nums, vector<vector<bool>>& vis, int x, int y, int id){
        if(x == nums.size()-1 && y == nums[0].size() - 1){
            return{true, 1};
        }
        if(nums[x][y] == 'X'){
            return {false, 0};
        }
        // if(nums[x][y] == '.' && id == 0){
        //     for(int i = 0; i < )
        // }
    }
    int get_ans(vector<vector<char>>& nums){
        int m = nums.size();
        int n = nums[0].size();
        int ans = -1;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        pair<bool, int> temp = dfs(nums, vis, 0, 0, 0);
        return -1;
    }
};
int main(){
    vector<vector<char>> vec;
    vector<char> temp;
    int N, M;
    cin>>M>>N;
    char item;
    for(int i = 0; i < M; ++i){
        temp.clear();
        for(int j = 0; j < N; ++j){
            cin>>item;
            temp.push_back(item);
        }
        vec.push_back(temp);
    }
    
    Solution s1;
    int ans = s1.get_ans(vec);
    cout<<ans;
}