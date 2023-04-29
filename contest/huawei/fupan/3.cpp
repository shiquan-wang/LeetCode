#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

struct Tree
{
    /* data */
    int p;
    int r;
    int v;
};


class Solution{
public:
    static bool cmp(Tree& a, Tree& b){
        return a.p + a.r < b.p + b.r;
    }
    int get_max_value(vector<Tree>& trees){
        /* 
        1,dp数组定义，
        dp[i][0], 前0-i棵树不种i树的最大价值
        dp[i][1], 前0-i棵树种i树的最大价值
        2,递推公式，
        dp[i][0] = max(dp[i-1][0], dp[i-1][1])，不种i树时i树和前0-i-1树之间不发生位置冲突
        dp[i][1] = max(dp[k][1] : k in p[k] + r[k] <= p[i] - r[i]) + v[i]，种i树，则取不发生冲突的树中价值最高者加v[i]
        3，初始状态
        dp[0][0] = 0
        dp[0][1] = v[0]
        4,遍历顺序
        for i in range(1, n-1)
        5,递推数组
        p = {2, 3, 4, 5} r = {1, 1, 1, 2}, v = {50, 10, 40, 70}
        i           0   1   2   3
        dp[i][0]    0   50  50  90
        dp[i][1]    50  10  90  120
         */
        int n = trees.size();
        
        sort(trees.begin(), trees.end(), cmp);//对右边界进行升序排列

        vector<vector<long long>> dp(n, vector<long long>(2, 0));
        dp[0][0] = 0; dp[0][1] = trees[0].v;//初始化
        for(int i = 1; i < n; ++i){//遍历得到dp数组
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            long long temp = 0;
            for(int j = 0; j < i && trees[j].p + trees[j].r <= trees[i].p - trees[i].r; ++j){
                temp = max(temp, dp[j][1]);
            }
            dp[i][1] = temp + trees[i].v;
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};
int main(){
    int N;
    cin>>N;
    Solution s1;
    // vector<int> position;
    // vector<int> radius;
    // vector<int> value;
    vector<Tree> trees(N);
    int item;
    for(int i = 0; i < N; ++i){
        cin>>item;
        trees[i].p = item;
    }
    for(int i = 0; i < N; ++i){
        cin>>item;
        trees[i].r = item;
    }
    for(int i = 0; i < N; ++i){
        cin>>item;
        trees[i].v = item;
    }
    cout<<s1.get_max_value(trees);
}