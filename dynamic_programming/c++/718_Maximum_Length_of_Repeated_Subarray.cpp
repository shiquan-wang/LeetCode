#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int findLength(vector<int>& nums1,  vector<int>& nums2){
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        //dp[i][j] : 以nums1[i-1] 和 nums2[j-1] 结尾的最长重复子序列（子数组）

        int res = 0;
        for(int i = 1; i <= nums1.size(); ++i){
            for(int j = 1; j <= nums2.size(); ++j){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;//递推公式
                }
                if(res < dp[i][j]){
                    res = dp[i][j];
                }
                cout<<dp[i][j]<<"\t";
            }
            cout<<"\n";
        }

        return res;
    }
};

int main(){
    vector<int> nums1 = {1, 2, 3, 2, 1};
    vector<int> nums2 = {3, 2, 1, 4, 7};
    Solution s;
    int res = s.findLength(nums1, nums2);
}