#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int minDistance(string word1, string word2){
        //dp[i][j] : 表示以i-1为结尾的字符串Word1 和以j-1为结尾的字符串word2 最近编辑距离是dp[i][j]

        //if word1[i-1] == word2[j-1] 不操作， dp[i][j] = dp[i-1][j-1]
        //word1[i-1] != word2[j-1] : word1 删除一个元素， dp[i][j] = dp[i-1][j] + 1     word2删除一个元素， dp[i][j] = dp[i][j-1] + 1       !!! word1添加一个元素相当于word2删除一个元素
        //替换一个元素， word1 替换 word1[i-1] 使其与 Word2[j-1] 相同，此时不用增加元素， dp[i][j] = dp[i-1][j-1] + 1

        //初始化：dp[i][0] = i, word1删除i个字符； dp[0][j] = j, word1添加i个字符

        //遍历顺序

        //dp数组

        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

        for(int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        for(int j = 0; j <= word2.size(); j++) dp[0][j] = j;

        for(int i = 1; i <= word1.size(); i++){
            for(int j = 1; j <= word2.size(); j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                cout<<dp[i][j]<<"\t";
            }
            cout<<"\n";
        }

        return dp[word1.size()][word2.size()];
    }
};

int main(){
    string word1 = "horse";
    string word2 = "ros";
    Solution s;
    int res = s.minDistance(word1, word2);
}