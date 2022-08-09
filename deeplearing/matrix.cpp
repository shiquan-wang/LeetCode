#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> matrix_muti(vector<vector<int>> matrix1, vector<vector<int>> matrix2){
        if(matrix1[0].size() != matrix2.size()){
            return {};
        }
        vector<vector<int>> res(matrix1.size(), vector<int>(matrix2[0].size(), 0));
        for(int i = 0; i < matrix1.size(); ++i){
            for(int j = 0; j < matrix2[0].size(); ++j){
                for(int k = 0; k < matrix1[0].size(); ++k){//第i行*第j列
                    res[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        return res;
    }
};

int main(){
    // vector<vector<int>> matrix1 = {{3, 3, 1}, {2, 3, 1}};
    // vector<vector<int>> matrix2 = {{2, 2}, {3, 1}, {1, 3}};
    vector<vector<int>> matrix1;
    vector<vector<int>> matrix2;
    int m, n, p;
    cin>>m>>n>>p;
    while (m --)
    {
        vector<int> temp;
        int item;
        for(int i = 0; i < n; ++i){
            cin>>item;
            temp.push_back(item);
        }
        matrix1.push_back(temp);
    }
    while (n --)
    {
        vector<int> temp;
        int item;
        for(int i = 0; i < p; ++i){
            cin>>item;
            temp.push_back(item);
        }
        matrix2.push_back(temp);
    }
    
    Solution s1;
    vector<vector<int>> res = s1.matrix_muti(matrix1, matrix2);
    for(auto vec : res){
        for(auto item : vec){
            cout<<item<<" ";
        }
        cout<<endl;
    }
}