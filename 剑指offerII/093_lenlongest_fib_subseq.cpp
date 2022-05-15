#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
/* 
如果序列 X_1, X_2, ..., X_n 满足下列条件，就说它是 斐波那契式 的：
    n >= 3
    对于所有 i + 2 <= n，都有 X_i + X_{i+1} = X_{i+2}
给定一个严格递增的正整数数组形成序列 arr ，找到 arr 中最长的斐波那契式的子序列的长度。如果一个不存在，返回  0 。

动态规划：
1，dp[i][j], 表示a[i]和a[j]结尾的斐波那契数列的最大长度
2，首先存在a[k] + a[i] == a[j] 则 dp[i][j] = dp[k][i] + 1
3, 边界条件，初始化， 0 < i < n; i < j < n dp[i][j] = 2;
 */
class Solution{
public:
    int lenLongestFibSubseq(vector<int>& arr){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i = 0; i < n; ++i){//初始化
            for(int j = i+1; j < n; ++j){
                dp[i][j] = 2;
            }
        }

        int res = 0;

        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i){//mp 做一个值的映射，用于根据arr[i] 和 arr[j] 判断arr中是否存在 arr[k] = arr[j] - arr[i]
            mp[arr[i]] = i;
        }

        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                int temp = arr[j] - arr[i];
                if(mp.find(temp) != mp.end()){
                    int index = mp[temp];
                    if(index < i){
                        dp[i][j] = max(dp[i][j], dp[index][i] + 1);
                    }
                }
                res = max(res, dp[i][j]);
            }
        }
        return res > 2 ? res : 0;
    }
};