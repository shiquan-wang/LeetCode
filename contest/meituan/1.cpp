#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    int scch(vector<int>& nums, int t){
        int ans = 0, num = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(t + num <= nums[i]){
                num += t;
            }else{
                ans++;
            }
        }
        return ans;
    }
};
int main(){
    vector<int> vec;
    int N, T;
    cin>>N>>T;
    int item;
    for(int i = 0; i < N; ++i){
        cin>>item;
        vec.push_back(item);
    }
    sort(vec.begin(), vec.end());
    Solution s1;
    int ans = s1.scch(vec, T);
    cout<<ans;
}