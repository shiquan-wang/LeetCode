#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution{
public:
    void get_ans(vector<int>& nums, int total){
        int ans = -1;
        int n = nums.size();
        // int avg = total/n;
        sort(nums.begin(), nums.end());
        int i = nums[n-1];
        for(; i >= 1; --i){
            int temp = 0;
            for(int j = 0; j < n; ++j){
                if(nums[j] <= i){
                    temp += nums[j];
                }else{
                    temp += i;
                }
            }
            if(temp <= total){
                ans = i;
                break;
            }
        }
        if(ans == nums[n-1]){
            cout<<-1;
        }else{
            cout<<ans;
        }
    }
};
int main(){
    int N, T;
    cin>>N;
    Solution s1;
    vector<int> vec;
    for(int i = 0; i < N; ++i){
        int item;
        cin>>item;
        vec.push_back(item);
    }
    cin>>T;
    s1.get_ans(vec, T);
}