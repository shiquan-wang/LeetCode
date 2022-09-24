#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

class Solution{
public:
    void get_ans(vector<int>& h, vector<vector<int>>& opera){
        for(int i = 0; i < opera.size(); ++i){
            if(opera[i][0] == 1){
                sort(h.begin(), h.begin() + opera[i][1]);
            }else{
                sort(h.begin(), h.begin() + opera[i][1], greater<int>());
            }
        }

        for(int i = 0; i < h.size()-1; ++i){
            cout<<h[i]<<" ";
        }
        cout<<h[h.size()-1];
    }
};

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> vec1;
    vector<vector<int>> vec2;

    int a, b;
    for(int i = 0; i < n; ++i){
        cin>>a;
        vec1.push_back(a);
    }
    for(int i = 0; i < m; ++i){
        cin>>a>>b;
        vec2.push_back({a, b});
    }
    Solution s1;
    s1.get_ans(vec1, vec2);
}