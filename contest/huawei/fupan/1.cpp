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
        //二分查找寻找ans
        int left = 0, right = nums[n-1];//定义ans在区间[left, right]中
        while (left <= right)
        {
            int mid = (left + right)/2;
            long long temp = 0;
            for(int j = 0; j < n; ++j){
                if(nums[j] <= mid){
                    temp += nums[j];
                }else{
                    temp += mid;
                }
            }
            if(temp <= total){
                left = mid + 1;
                ans = max(ans, mid);
            }else{
                right = mid-1;
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