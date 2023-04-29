#include<iostream>
#include<vector>

using namespace std;


vector<int> point_num(100000, 0);
int n;

int dfs(vector<vector<int>>& vec, int point){
    int count = 0;
    bool flag = false;
    for(int i = 0; i < n; ++i){
        if(vec[point][i] == 1){
            flag = true;
            count += dfs(vec, i);
        }
    }
    if(flag == false){
        return 1;
    }else{
        return count;
    }
}

int main(){
    cin>>n;
    vector<vector<int>> vec(n, vector<int>(n, 0));
    int s, t;
    for(int i = 0; i < n; ++i){
        cin>>s>>t;
        vec[t-1][s-1] = 1;
    }

    int best_num, nums;



}