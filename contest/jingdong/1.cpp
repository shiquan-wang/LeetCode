#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    void martix(int n){
        vector<vector<int>> ans(n, vector<int>(n));
        vector<int> ji;
        vector<int> ou;
        for(int i = 1; i <= n*n; ++i){
            if(i % 2 == 0){
                ou.push_back(i);
            }else{
                ji.push_back(i);
            }
        }
        for(int i = 0; i < n; ++i){
            vector<int> temp;
            for(int j = 0; j < )
        }
    }
};
int main(){
    int n;
    cin>>n;
    Solution s;
    s.martix(n);
}