#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
 */

class Solution
{
private:
    /* data */
public:
    Solution(/* args */);
    ~Solution();
    int KthSmallest(vector<vector<int>>& matrix, int k){
        vector<int> temp;
        for(int i=0; i<matrix.size(); ++i){
            for(int j=0; j<matrix[0].size(); ++j){
                temp.push_back(matrix[i][j]);
            }
        }
        sort(temp.begin(), temp.end());
        return temp[k-1];
    //time: n^2logn  space : n^2
    }
//归并排序也可以，每一行都是有序的，每次选出来当前最小的数
//二分查找

    int kthSmallest(vector<vector<int>>& matrix, int k){
        

    }
};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}

int main(){
    int a[] = {1,5,9,10,11,13,12,13,15};
    vector<vector<int>> c(3, vector<int>(3));
    int t = 0;
    for(int i=0; i<3;++i){
        for(int j=0; j<3; ++j){
            c[i][j]=a[t];
            ++t;
        }
    }
    Solution s;
    cout<<s.KthSmallest(c, 8);
}