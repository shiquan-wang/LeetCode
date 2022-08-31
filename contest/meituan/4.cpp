#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int nums_target(vector<int>& nums){
        int ans = 0;
        for(int i = 0; i <= nums.size() - 3; ++i){
            for(int j = i + 1; j <= nums.size() - 2; ++j){
                for(int k = j + 1; k <= nums.size() - 1; ++k){
                    if(nums[i] + nums[k] == 3 * nums[j]){
                        ans++;
                        cout<<i<<j<<k;
                    }
                }
            }
        }
        return ans;
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
    cout<<s1.nums_target(vec);
}