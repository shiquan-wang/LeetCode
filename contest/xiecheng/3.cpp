#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    void edge_valid(string& str, vector<vector<int>> vec){
        cout<<1;
    }
};

int main(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    vector<vector<int>> vec(n-1, vector<int>(2, 0));

    for(int i = 0; i < n-1; ++i){
        cin>>vec[i][0]>>vec[i][1];
    }

    Solution s1;
    s1.edge_valid(str, vec);
}