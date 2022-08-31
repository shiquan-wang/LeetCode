#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    void pinghua(vector<int>& nums){
        int n = nums.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        for(int i = 1; i < n; ++i){
            left[i] = max(left[i-1], abs(nums[i] - nums[i-1]));
        }
        for(int i = n-2; i > 0; --i){
            right[i] = max(right[i+1], abs(nums[i] - nums[i+1]));
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; ++i){
            if(i == 0){
                ans = min(ans, right[i+1]);
            }else if(i == n-1){
                ans = min(ans, left[i-1]);
            }else{
                int temp = max(left[i-1], right[i+1]);
                temp = max(temp, (abs(nums[i+1] - nums[i-1]) + 1) / 2);
                ans = min(ans, temp);
            }
        }
        cout<<ans;
    }
};
int main(){
    vector<int> vec;
    int N, item;
    cin>>N;
    for(int i = 0; i < N; ++i){
        cin>>item;
        vec.push_back(item);
    }
    Solution s1;
    s1.pinghua(vec);
}