#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    pair<bool,int> is_great(vector<int>& nums, int l, int r){
        bool flag = true;
        int lowest = nums[l];
        for(int i = l; i <= r; ++i){
            if(nums[i] <= 0){
                flag = false;
                break;
            }
            lowest = min(lowest, nums[i]);
        }
        return {flag, lowest};
    }
    long long scch(vector<int>& nums, int m){
        long long ans = 0;
        int left = 0, right = m-1;
        while (right < nums.size())
        {
            pair<bool, int> temp = is_great(nums, left, right);
            if(temp.first == true){
                int index = m;
                for(int j = left; j <= right; ++j){
                    nums[j] -= temp.second;
                    
                    if(nums[j] == 0){
                        index = j - left;
                    }
                    
                }
                left += index;
                right += index;
            }
            ++left;
            ++right;
        }
        for(auto item: nums){
            ans += item;
        }
        return ans;
    }
};
int main(){
    int N, M;
    cin>>N>>M;
    vector<int> nums;

    int item;
    for(int i = 0; i < N; ++i){
        cin>>item;
        nums.push_back(item);
    }
    Solution s1;
    long long ans = s1.scch(nums, M);
    cout<<ans;
}