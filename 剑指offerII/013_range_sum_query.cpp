#include<iostream>
#include<vector>

using namespace std;

class NumArray1D{
public:
    vector<int> sums;
    NumArray1D(vector<int>& nums){
        int n = nums.size();
        sums.resize(n+1);
        sums[0] = 0;
        for(int i = 0; i < n; ++i){
            sums[i+1] = sums[i] + nums[i];
        }
        
    }

    int sumRange(int left, int right){
        return sums[right+1] - sums[left];
    }


};

class NumMatrix{
public:
    vector<vector<int>> sums;

    NumMatrix(vector<vector<int>> matrix){
        int m = matrix.size();
        if(m > 0){
            int n = matrix[0].size();
            sums.resize(m, vector<int>(n+1));
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    sums[i][j+1] = sums[i][j] + matrix[i][j];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2){
        int sum = 0;
        for(int i = row1; i <= row2; ++i){
            sum += (sums[i][col2 + 1] - sums[i][col1]);
        }
        return sum;
    }
};