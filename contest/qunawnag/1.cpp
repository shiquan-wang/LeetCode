class Solution {
public:
    // /**
    //  * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
    //  *
    //  * 运动员可得到的最高分
    //  * @param energy int整型 运动员体力值
    //  * @param actions int整型vector<vector<>> 二维数组i为动作号 actions[i][0]为动作i+1消耗体力,actions[i][1]为动作i+1得分
    //  * @return int整型
    //  */
    int maxScore(int energy, vector<vector<int> >& actions) {
        // write code here
//         vector<int> dp(actions.size(), 0);
        int n = actions.size();
        vector<vector<int>> dp(n, vector<int>(energy+1, 0));
        
        for(int j = actions[0][0]; j <= energy; ++j){
            dp[0][j] = actions[0][1];
        }
        
        for(int i = 1; i < n; ++i){
            for(int j = 0; j <= energy; ++j){
                if(j < actions[i][0]){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-actions[i][0]] + actions[i][1]);
                }            
            }
        }
        return dp[n-1][energy];
    }
};