#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    int scch(vector<int>& nums, long long k){
        int n = nums.size();
        int i = 0;
        while (k > 0)
        {
            /* code */
            if(nums[i%n] != 0){
                k--;
                nums[i%n]--;
            }
            i++;
        }
        
        return i%n;
    }
};
int main(){
    vector<int> vec;
    long long N, K;
    cin>>N>>K;
    int item;
    for(int i = 0; i < N; ++i){
        cin>>item;
        vec.push_back(item);
    }
    
    Solution s1;
    int ans = s1.scch(vec, K);
    cout<<ans;
}