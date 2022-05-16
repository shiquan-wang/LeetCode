#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/* 
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。
返回符合要求的 最少分割次数 。
思路：
使用回溯法将所有可能的分割方式存储起来，最后寻找最少分割次数
timely out，改进思路，使用动态规划来代替双指针来判断一个子串是否是回文字符串
继续超时

改换思路，动态规划
1，dp[i] 代表s[0,...i]的最少分割次数，
2，如果s[0] - s[i]本身是回文子串，那么dp[i] = 0,
    否则, 如果s[j] - s[i]是回文，则dp[i] = dp[j-1] + 1
我们要求 dp[i]，可以根据它前面的状态进行转移，如果存在某个位置0<=j<=i，使得 s[j...i] 为回文串，则只要知道 s[0...j−1] 的最小分割次数，就能求出s[0...i] 的最小分割次数，因为s[j...i] 为一个回文串。
3, 初始化 dp[0] = 0
4, 遍历顺序，0 < i < s.size(); ++i
5, 举例推导dp数组 aab dp[] : 0, 0, 1
 */ 

class Solution{
private:
    vector<vector<string>> substrs;
    vector<string> path;
    vector<vector<bool>> dp;
    // int res;
public:
    bool is_palindrome(const string& s, int start, int end){//判断string从start到end是否是回文字符串
        
        while (start < end)
        {
            if(s[start] != s[end]){
                return false;
            }
            ++start;
            --end;
        }

        return true;
    }
    void is_palindrome_dp(const string& s){
        for(int i = s.size() -1; i >= 0; --i){
            for(int j = s.size() - 1; j > i; --j){
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
            }
        }
    }
    void backtracking(const string& s, int start_index){
        if(start_index >= s.size()){//终止条件
            substrs.push_back(path);
            return;
        }

        for(int i = start_index; i < s.size(); ++i){
            /* if(is_palindrome(s, start_index, i)){//start_index - i之间的字符串是回文字符串，可以进行分割。
                path.push_back(s.substr(start_index, i - start_index + 1));
                backtracking(s, i+1);
                path.pop_back();
            }else{
                continue;
            } */
            if(dp[start_index][i]){//start_index - i之间的字符串是回文字符串，可以进行分割。
                path.push_back(s.substr(start_index, i - start_index + 1));
                backtracking(s, i+1);
                path.pop_back();
            }else{
                continue;
            }
        }
    }
    int minCut(string s){
        substrs.clear();
        path.clear();
        dp.assign(s.size(), vector<bool>(s.size(), true));
        is_palindrome_dp(s);
        backtracking(s, 0);
//将所有的可能分割结果存储在substrs中，此时substrs中每个数组的长度减1就是相应的分割次数
        int res = INT_MAX;
        for(auto item : substrs){
            res = min(res, (int)(item.size() - 1));
        }
        return res;
    }

    int minCut_dp(string s){
        dp.assign(s.size(), vector<bool>(s.size(), true));
        is_palindrome_dp(s);//动态规划法快速得出s[i] - s[j]之间的子串是否是回文子串

        vector<int> dp_sub(s.size(), 0);
        for(int i = 0; i < s.size(); ++i){
            if(dp[0][i]){//如果s[0] - s[i]是回文子串，那么s[0] - s[i]之间不需要分割
                dp_sub[i] = 0;
            }else{//如果s[0] - s[i]不是回文子串，那么s[0] - s[i]之间需要分割
                for(int j = 1; j <= i; ++j){//如果s[j] - s[i]是回文子串，那么可以在s[j-1] 和 s[j]之间将其分割，此时s[0] - s[i]之间的分割次数等于s[0] - s[j-1]之间的分割次数加一， dp[i] = dp[j - 1] + 1
                    if(dp[j][i]){
                        dp_sub[i] = min(dp_sub[i], dp_sub[j-1] + 1);
                    }
                }
            }
        }
        return dp_sub[s.size() - 1];
    }
};

int main(){
    string s = "aab";
    Solution s1;
    cout<<s1.minCut_dp(s);
}