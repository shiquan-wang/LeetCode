#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int multiple_backpack(vector<int>& weight, vector<int>& value, vector<int> nums, int bag_size){//nums 代表第i个物品有几个
        for(int i = 0; i < nums.size(); ++i){//将nums[i]变为1,即将多重背包平铺为01背包
            while(nums[i] > 1){
                weight.push_back(weight[i]);
                value.push_back(value[i]);
                nums[i]--;
            }

            vector<int> dp(bag_size + 1, 0);
            for(int i = 0; i < weight.size(); ++i){//遍历物品，
                for(int j = bag_size; j >= weight[i]; --j){//遍历背包
                    dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
                }
            }

            return dp[bag_size];
        }
    }
};

int main(){
    int n;
    while(cin>>n){
        for(int i = 0; i < n; ++i){
            
        }
    }
}