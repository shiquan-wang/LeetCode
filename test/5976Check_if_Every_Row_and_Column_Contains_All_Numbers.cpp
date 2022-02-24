#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    bool check(vector<int>& nums){//检测每一行或每一列是否包含1-n的整数
        int n = nums.size();
        vector<int> temp(n+1, 0);
        for(int i = 0; i < n; ++i){//记录每一行/列的整数，
            temp[nums[i]]++;
        }
        for(int i = 1; i < n+1; ++i){//遍历temp,观察是否只包含1-n的整数
            if(temp[i] != 1){
                return false;
            }
        }
        return true;
    }
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        for(int i = 0; i < n; ++i){
            bool row_res = check(matrix[i]);//检测行
            // cout<<"row_res"<<i<<row_res<<"\n";
            vector<int> column;
            for(int j = 0; j < n; ++j){
                column.push_back(matrix[j][i]);
            }
            // for(int i : column){
            //     cout<<i;
            // }
            // cout<<"\n";
            bool column_res = check(column);//检测列
            // cout<<"column_res"<<i<<column_res<<"\n";
            column.clear();
            if(row_res == false || column_res == false){
                return false;
            }
        }
        return true;
    }
};

int main(){
    vector<vector<int>> martix = {{1, 2, 3}, {3, 1, 2}, {2, 3, 1}};
    vector<vector<int>> martix2 = {{1, 2, 3}, {1, 1, 2}, {2, 3, 1}};
    vector<vector<int>> martix3 = {{1, 2, 3}, {2, 1, 3}, {3, 2, 1}};
    Solution s1;
    bool res = s1.checkValid(martix3);
    cout<<res;
}