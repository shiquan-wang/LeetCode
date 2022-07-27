/* 
作弊能得到的最大得分
有n道题目
每道题目有不能作弊的得分、 能作弊的得分、作弊风险
问 作弊风险最多不能超过k能得到的最大得
 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int most_ratting(vector<int> a, vector<int> b, vector<int> c, int k){
        vector<vector<int>> dp(a.size(), vector<int>(k, 0));
        //初始化
        for(int i = 0; i < a.size(); ++i){
            dp[i][0] = 0;
        }
        for(int i = 0; i < k; ++i){
            if(c[0] > k){
                dp[0][i] = a[0];
            }else{
                dp[0][i] = max(a[0], b[0]);
            }
            
        }

        for(int i = 0; i < a.size(); ++i){
            for(int j = 0; j < k; ++j){
                dp[i][j] = 
            }
        }
    }
};

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for(int i = 0; i < n; ++i){
        cin>>a[i];
    }
    // for(int j = 0; j < n; ++j){
    //     cout<<a[j];
    // }
    // cout<<endl;
    for(int i = 0; i < n; ++i){
        cin>>b[i];
    }
    // for(int j = 0; j < n; ++j){
    //     cout<<b[j];
    // }
    // cout<<endl;
    for(int i = 0; i < n; ++i){
        cin>>c[i];
    }
    // for(int j = 0; j < n; ++j){
    //     cout<<c[j];
    // }
    // for(int j = 0; j < n; ++j){
    //     cout<<a[j]<<b[j]<<c[j]<<endl;
    // }
    /* 
    vector<int> list1;默认初始化，最常用
此时，vector为空， size为0，表明容器中没有元素，而且 capacity 也返回 0，
意味着还没有分配内存空间。这种初始化方式适用于元素个数未知，需要在程序中动态添加的情况
此时不能直接访问下标，只能通过pushback操作添加元素
     */
    Solution s1;
}