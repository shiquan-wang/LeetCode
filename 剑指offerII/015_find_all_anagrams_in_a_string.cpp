#include<iostream>
#include<vector>
#include<string>

using namespace std;
/* 
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。
不考虑答案输出的顺序。

异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。

 */
class Solution{
public:
    vector<int> findAnagrams(string s, string p){
        int ls = s.length(), lp = p.length();
        vector<int> res;
        vector<int> cnt_s(26), cnt_p(26);//分别存放s 和 p的字符数目，是s[0] = 2代表s 存在2个a

        for(int i = 0; i < lp; ++i){//第一个窗口
            cnt_p[p[i] - 'a']++;
            cnt_s[s[i] - 'a']++;
        }

        if(cnt_s == cnt_p){
            res.push_back(0);
        }

        for(int i = lp; i <= (ls - lp); ++i){//向右滑动窗口，并更新cnt_s中包含字符的数目
            ++cnt_s[s[i] - 'a'];
            --cnt_s[s[i-lp] - 'a'];
            if(cnt_s == cnt_p){
                res.push_back(i);
            }
        }
        

        return res;

    }
};

int main(){
    Solution s1;
    vector<int> ans = s1.findAnagrams("abab", "ab");
    for(auto iter : ans){
        cout<<iter<<" ";
    }
}