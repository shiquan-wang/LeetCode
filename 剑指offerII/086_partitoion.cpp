#include<iostream>
#include<vector>
#include<string>

using namespace std;
/* 
给定一个字符串 s ，请将 s 分割成一些子串，使每个子串都是 回文串 ，返回 s 所有可能的分割方案。
思路：找到所有可能的解，使用回溯法
回溯三部曲： 递归参数，终止条件 ，单层处理逻辑
*/
class Solution{
private:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<bool>> dp;
public:
    bool is_palindrome(const string& s, int left, int right){
        while (left < right)
        {
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
    //进阶思路，使用动态规划的方式来判断字符串s从left到right区间内的子字符串是否为回文字符串，可以减少双指针判断的时间
    /* 
    动态规划预处理字符串s，
    1 dp[i][j] 代表字符串s从i到j是否是回文字符串
    2 dp[i][j] = dp[i+1][j-1] ^ s[i] == s[j] {i < j}, 当s[i] == s[j]并且dp[i+1][j-1]为true时dp[i][j]为true 
      dp[i][j] = true {i == j} 为了便于初始化，将i>j位置的动态规划数组也初始化为true
    3 初始化，i==j dp[i][j] = true;
    4 遍历顺序，右上到左下， i递加 j递减，
    5 举例推导dp数组
     */
    void is_palindrome_dp(const string& s){
        for(int i = s.size() - 1; i >= 0; --i){
            for(int j = s.size() -  1; j > i; --j){
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
            }
        }
        for(auto vec : dp){
            for(auto flag : vec){
                cout<< flag<<" ";
            }
            cout<<endl;
        }
    }

    void backtracking(string& s, int start_index){
        if(start_index >= s.size()){
            res.push_back(path);
            return;
        }

        for(int i = start_index; i < s.size(); ++i){
            /* if(is_palindrome(s, start_index, i)){//相当于从start_index开始到i结束，这一段作为一个小的子字符串，判断这个字符串是否是回文字符串
                path.push_back(s.substr(start_index, i - start_index + 1));
            }else{
                continue;//start_index到i的子字符串不是回文字符串则判断下一个切割点
            } */
            if(dp[start_index][i]){//相当于从start_index开始到i结束，这一段作为一个小的子字符串，判断这个字符串是否是回文字符串
                path.push_back(s.substr(start_index, i - start_index + 1));
            }else{
                continue;//start_index到i的子字符串不是回文字符串则判断下一个切割点
            }
            backtracking(s, i+1);//寻找起始位置是i+1的回文子字符串
            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s){
        res.clear();
        path.clear();
        dp.assign(s.size(), vector<bool>(s.size(), true));
        is_palindrome_dp(s);
        backtracking(s, 0);
        return res;
    }
};

int main(){
    string s = "aab";
    Solution s1;
    vector<vector<string>> res = s1.partition(s);
    for(auto vec : res){
        for(auto str : vec){
            cout<<str<<" ";
        }
        cout<<endl;
    }
}