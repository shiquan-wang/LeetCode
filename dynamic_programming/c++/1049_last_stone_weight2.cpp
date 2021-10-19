#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int lastStoneWeightII(vector<int>& stones){
        int sum = 0;
        for(auto i : stones) sum += i;
        int target = sum / 2;
        vector<int> dp(target+1, 0);
        for(int i = 0; i < stones.size(); ++i){
            for(int j = target; j >= stones[i]; --j){
                dp[j] = max(dp[j], dp[j-stones[i]] + stones[i]);
            }
            for(int i : dp) cout<<i<<" ";
        }

        return sum  -dp[target] - dp[target];
    }
    int laststones(vector<int>& stones){
        int sum = 0;
        for(auto i : stones) sum += i;
        int target = sum / 2;
        vector<vector<int>> dp(stones.size(), vector<int>(target+1, 0));

        for(int i = stones[0]; i <= target; ++i){//初始化
            dp[0][i] = stones[0];
        }

        for(int i=1; i < stones.size(); ++i){//i从1开始，因为0这一行已经初始化了
            for(int j = 0; j <= target; ++j){
                if(j < stones[i]){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-stones[i]] + stones[i]);
                }
            }
        }

        return sum - 2 * dp[stones.size()-1][target];
    }
};
//本题其实就是尽量让石头分成重量相同的两堆，相撞之后剩下的石头最小，这样就化解成01背包问题了。
//是不是感觉和昨天讲解的416. 分割等和子集非常像了。
//最后dp[target]里是容量为target的背包所能背的最大重量。
//那么分成两堆石头，一堆石头的总重量是dp[target]，另一堆就是sum - dp[target]。
//在计算target的时候，target = sum / 2 因为是向下取整，所以sum - dp[target] 一定是大于等于dp[target]的。
//那么相撞之后剩下的最小石头重量就是 (sum - dp[target]) - dp[target]。
int main(){
    vector<int> stones = {2, 4, 1, 1};
    Solution s;
    int res = s.lastStoneWeightII(stones);
}