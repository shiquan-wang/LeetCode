#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
private:
    int ans;
    vector<int> temp;
public:
    bool is_valid(vector<int>& temp, int k){
        int count = 0;
        int max_temp = 0;
        for(auto item: temp){
            count += item;
            if(max_temp < item){
                max_temp = item;
            }
        }
        float avg = (count/(temp.size()*1.0));
        cout<<"avg"<<avg;
        return max_temp > avg*k ? false : true;
    }
    void backtracking(vector<int>& nums, int start_index, int k){
        if(is_valid(temp, k)){
            int len = temp.size();
            ans = max(ans, len);
        }else{
            return;
        }
        for(int i = start_index; i < nums.size(); ++i){
            temp.push_back(nums[i]);
            backtracking(nums, i+1, k);
            temp.pop_back();
        }
    }
    // int get_ans(vector<int>& nums, int k){
    //     temp.clear();
    //     ans = 0;
    //     backtracking(nums, 0, k);
    //     return ans;
    // }
    int get_ans(vector<int>& nums, int k){
        ans = nums.size()+1;
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i = 0; i < nums.size(); ++i){
            count += nums[i];
        }
        float avg = (count*1.0)/(nums.size() * 1.0);
        for(int i = nums.size()-1; i >= 0; --i){
            if(nums[i] > k*avg){
                ans--;
                count -= nums[i];
                avg = (count*1.0)/(i*1.0);
            }
        }
    }
};
int main(){
    int n, k;
    cin>>n>>k;
    vector<int> nums;
    int item;
    for(int i = 0; i < n; ++i){
        cin>>item;
        nums.push_back(item);
    }
    Solution s1;
    int ans = s1.get_ans(nums, k);
    cout<<ans;
}