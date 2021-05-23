#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c){
        int m = mat.size();
        int n = mat[0].size();
        if(m*n != r*c){
            return mat;
        }
        vector<vector<int>> temp(r, vector<int>(c));
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                int num = i*n+j;
                temp[num/c][num%c] = mat[i][j];  //关键在于 i = num/n  j = num%n
            }
        }
        /* 
        for(int num=0; num<m*n; ++num){
            temp[num/c][num%c] = mat[num/n][num%n];     
        }
         */
        return temp;
    }
};

int main(){
    vector<vector<int>> c(2,vector<int>(2));
    Solution s;
    c = s.matrixReshape(c, 1, 4); 
    cout<<"[";
    for(int i=0; i<c.size();++i){
        cout<<"[";
        for(int j=0; j<c[0].size();++j){
            cout<<c[i][j]<<" ";
        }
        cout<<"]";
        if(i != c.size()-1) cout<<endl;
    }
    cout<<"]";
}
