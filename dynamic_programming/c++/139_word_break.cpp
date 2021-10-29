#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;
/* 
题目描述：Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

 */
class Solution{
public:
    bool wordBreak(string s, vector<string> wordDict){
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for(int j = 1; j <= s.size(); ++j){
            for(int i = 0; i < j; ++i){
                string word = s.substr(i, j - i);
                if(wordSet.find(word) != wordSet.end() && dp[i]){
                    dp[j] = true;
                }
            }
        }

        return dp[s.size()];
    }

/*     bool wordBreak2(string s, vector<string> wordDict){
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for(int i = 0; i < wordDict.size(); ++i){
            for(int j)
        }
    } */
};