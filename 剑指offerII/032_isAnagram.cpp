#include<iostream>
#include<string>
#include<vector>
using namespace std;
/* 
给定两个字符串 s 和 t ，编写一个函数来判断它们是不是一组变位词（字母异位词）。

注意：若 s 和 t 中每个字符出现的次数都相同且字符顺序不完全相同，则称 s 和 t 互为变位词（字母异位词

思路：遍历两个字符串，如果字符相同直接返回false,否则将其存储在hashmap中，value++,当两个字符串遍历结束后，如果两个hashmap相同则是变位词

改进思路1：遍历s时++ 遍历t时--，减少一个hashmap的使用
改进思路2：使用数组来代替hashmap,因为只包含小写字母
 */
class Solution{
public:
    bool isAnagram(string s, string t){
        if(s.size() != t.size()) return false;
        
        vector<int> vec(26, 0);//26个小写字母
        bool res = false;//如果字符出现顺序不完全相同res = true
        for(int i = 0; i < s.size(); ++i){
            // if(s[i] == t[i])
            if(s[i] != t[i]){//判断字符顺序
                res = true;
            }
            vec[s[i] - 'a']++;
            vec[t[i] - 'a']--;
        }

        for(int item : vec){
            if(item != 0) return false;//字符出现次数不相同
        }

        return res;
       
    }
};