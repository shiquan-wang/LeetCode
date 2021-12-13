#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int minDistance(string word1, string word2){
        //dp[i][j] : 以i-1为结尾的字符串word1 和以j-1结尾的字符串Word2，要想相等需要删除的最少元素个数。

        //word1[i-1] == word2[j-1]  dp[i][j] = dp[i-1][j-1]
        //word1[i-1] != word2[j-1]      case1: 删除word1[i-1], dp[i-1][j] + 1               case2: 删除word2[j-1]，dp[i][j-1] + 1         case3:删除word1[i-1] 和 word2[j-1] , dp[i-1][j-1] + 2

        //初始化： dp[i][0] : word1[i-1]结尾的字符串变为空字符串需要删除i个字符，故dp[i][0] = i        同理dp[0][j] = j

        //遍历顺序： 从左到右，从上到下

        //推导dp数组

        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for(int i = 0; i <= word1.size(); ++i) dp[i][0] = i;
        for(int j = 0; j <= word2.size(); ++j) dp[0][j] = j;

        for(int i = 1; i <= word1.size(); ++i){
            for(int j = 1; j <= word2.size(); ++j){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 2});
                }
            }
        }
        return dp[word1.size()][word2.size()];

    }
};

int main(){
    string word1 = "bagge";
    string word2 = "bag";
    Solution s;
    int res = s.minDistance(word1, word2);
}