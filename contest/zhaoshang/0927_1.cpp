#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    void get_ans(vector<int>& nums){
        int min_num = nums[0], max_num = nums[0],max_len = 0;
        int n = nums.size();
        vector<int> dp(n, 0);
        if(nums[0] >= 80){
            dp[0] = 1;
        }else{
            dp[0] = 0;
        }
        for(int i = 1; i < n; ++i){
            min_num = min(min_num, nums[i]);
            max_num = max(max_num, nums[i]);

            if(nums[i] >= 80){
                dp[i] = dp[i-1] + 1;
            }else{
                dp[i] = 0;
            }
            max_len = max(max_len, dp[i]);
        }

        cout<<max_num - min_num<<endl;
        cout<<max_len;
    }
};

int main(){
    int n;
    cin>>n;
    int item;
    vector<int> a;
    for(int i = 0; i < n; ++i){
        cin>>item;
        a.push_back(item);
    }
    Solution s1;
    s1.get_ans(a);
}