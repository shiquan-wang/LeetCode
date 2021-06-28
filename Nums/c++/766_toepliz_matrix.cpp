#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    /* data */
public:
    Solution(/* args */);
    ~Solution();
    bool isToeplitzMatrix(vector<vector<int>>& matrix){
        int r = matrix.size(), c = matrix[0].size();
        bool tag = true;
        for(int i=1;i<r;++i){
            for(int j=1;j<c;++j){
                if(matrix[i][j] != matrix[i-1][j-1]){
                    return false;
                }
            }
        }
        return true;
    }
};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}
int main(){
    vector<vector<int>> v(3, vector<int>(4));
    v[0] = {1, 2, 3, 4};
    v[1] = {5, 1, 2, 3};
    v[2] = {9, 5, 1, 2};
    Solution s;
    cout<<s.isToeplitzMatrix(v);
}