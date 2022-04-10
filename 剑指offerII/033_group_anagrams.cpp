#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

/* 
给定一个字符串数组 strs ，将 变位词 组合在一起。 可以按任意顺序返回结果列表。

注意：若两个字符串中每个字符出现的次数都相同，则称它们互为变位词。

思路一：遍历字符串数组，两两比较，如果是异位词，组成列表，结果超时 ,时间复杂度O(n^2)，虽然有flag数组优化，但是还是超时
思路二：题解思路，使用哈希表来存储，key标志着一组异位词，即每个字母的数量，value是互为异位词的字符串列表
 */

class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        if(strs.size() == 1) return {strs};

        vector<vector<string>> res;
        vector<bool> flag(strs.size(), false);
        for(int i = 0; i < strs.size(); ++i){
            if(flag[i] == true) continue;

            vector<string> temp;
            temp.push_back(strs[i]);

            for(int j = i+1; j < strs.size(); ++j){//统计strs[i]的变位词
                if(flag[j] == true) continue;//strs[j]已经是某一个的变位词了，不需要再次判断

                if(is_anagrams(strs[i], strs[j])){//strs[i] 和 strs[j]是变位词
                    temp.push_back(strs[j]);
                    flag[j] = true;
                }
            }

            flag[i] = true;//这一步要不要无所谓
            res.push_back(temp);
        }
        return res;
    }

    bool is_anagrams(string s, string t){
        if(s.size() != t.size()) return false;

        vector<int> vec(26, 0);
        
        for(int i = 0; i < s.size(); ++i){
            vec[s[i] - 'a']++;
            vec[t[i] - 'a']--;
        }

        for(auto item : vec){
            if(item != 0) return false;
        }

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs){
        if(strs.size() == 1) return {strs};
//关键在于key值怎么确认，使用vector不太方便，第一个使用排序后的字符串作为map的key值，第二种使用a3b2c1这样的字符串来作为key值                                                             
        unordered_map<string, vector<string>> mp; 

        for(auto item : strs){//遍历strs,对其中的每一个元素都进行排序，将排序后的字符串作为键，将原字符串作为值插入哈希表对应的键的vector中中。 因为异位字符串排序后是完全相同的。
            string temp = item;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(item);
        }

        vector<vector<string>> res;

        for(auto item = mp.begin(); item != mp.end(); ++item){
            res.push_back(item->second);
        }

        return res;
    }

    vector<vector<string>> groupAnagrams3(vector<string>& strs){
        
    }
};