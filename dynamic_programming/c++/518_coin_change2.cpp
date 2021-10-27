#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int change(int amount, vector<int>& coins){
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < coins.size(); ++i){
            for(int j = coins[i]; j <= amount; ++j){
                dp[j] += dp[j- coins[i]];
            }
            for(int i : dp) cout<<i<<" ";
            cout<<endl;
        }
        return dp[amount];
    }
};

/* 
dp[j]：凑成总金额j的货币组合数为dp[j]
dp[j] += dp[j - coins[i]]
dp[0] = 1, 只有当不选取任何硬币时，金额之和才为 0
外层for循环遍历物品（钱币），内层for遍历背包（金钱总额  得到的方法数量只有{1, 5}这种情况 dp[j]里计算的是组合数
如果把两个for交换顺序 背包容量的每一个值，都是经过 1 和 5 的计算，包含了{1, 5} 和 {5, 1}两种情况。 此时dp[j]里算出来的就是排列数
 */
int main(){
    vector<int> coins = {1, 2, 5};
    Solution s;
    int res = s.change(5, coins);
}