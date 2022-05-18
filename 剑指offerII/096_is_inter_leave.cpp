#include<iostream>
#include<string>
#include<vector>

using namespace std;
/* 
给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。

两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...

思路：贪心法，依次遍历 结果错误
思路二：动态规划
1， dp[i][j] 代表s1的前i个元素和s2的前j个元素是否可以交错形成s3的前i+j个元素
2, 如果s1的第i个元素和s3的第i+j个元素相同，那么s1的前i个元素和s2的前j个元素能否交错构成s3的前i+j个元素取决于s1的前i-1个元素和s2的前j个元素是否可以交错形成s3的前i+j-1个元素，dp[i][j]由 dp[i-1][j]决定
   如果s2的第j个元素和s3的第i+j-1个元素相同，同理，dp[i][j] 由dp[i][j-1]决定
    if s1[i-1] == s3[i+j-1] dp[i][j] = dp[i-1][j]
    if s2[j-1] == s3[i+j-1] dp[i][j] = dp[i][j-1]
3, 边界条件 dp[0][0] = true
4, 遍历顺序
5, 举例推导dp数组
s1 = "aabcc" s2 = "dbbca" s3 = "aadbbcbcac"
dp
 */ 
class Solution{
public:
    bool isInterleave(string s1, string s2, string s3){
        if(s1.size() + s2.size() != s3.size()){//s1长度加s2长度不等于s3的长度直接返回false
            return false;
        }
        
        vector<vector<bool>> dp(s1.size() +1 , vector<bool>(s2.size() + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= s1.size(); ++i){
            if(s1[i-1] == s3[i-1]){
                dp[i][0] = dp[i-1][0];
            }
        }
        for(int j = 1; j <= s2.size(); ++j){
            if(s2[j-1] == s3[j-1]){
                dp[0][j] = dp[0][j-1];
            }
        }
        for(int i = 1; i <= s1.size(); ++i){
            for(int j = 1; j <= s2.size(); ++j){
                if(s1[i-1] == s3[i + j - 1]){
                    dp[i][j] =  dp[i][j] || dp[i-1][j];
                }
                if(s2[j-1] == s3[i + j - 1]){
                    dp[i][j] = dp[i][j] || dp[i][j-1];
                }
            }
        }

        return dp[s1.size()][s2.size()];
    }
};

int main(){
    Solution s1;
    cout<<s1.isInterleave("db", "b", "cbb");
}