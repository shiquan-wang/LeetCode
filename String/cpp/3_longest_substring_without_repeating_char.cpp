#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution{
public:
    int lengthOfLongestSubstring(string s){
        unordered_set<char> occ;
        int n = s.size();
        int r = -1, ans = 0;

        for(int i = 0; i < n; ++i){//类似暴力法，从每个下标处出发计算当前可以达到的最长无重复子串
            if(i != 0){
                occ.erase(s[i-1]); //左指针右移一位， set中除去s[i-1]位置的字符
            }
            while(r+1 < n && !occ.count(s[r+1])){ //右指针的下一个字符没有出现在set中，指针右移
                occ.insert(s[r+1]);
                ++r;
            }
            ans = max(ans, r-i+1);
        }

        return ans;
    }
    // int lengthOfLongestSubstring(string s){
    //     unordered_map<char, int> occ;
    //     int n = s.size();
    //     int r = -1, ans = 0;

    //     for(int i = 0; i < n; ++i){

    //     }
    // }
    int lengthOfLongestSubstring2(string s) {
        // if(s.size() == 0) return 0;
        unordered_map<char, int> mp;
        int res = 0;
        int start_index = 0, end_index = 0;
        for(int i = 0; i < s.size(); ++i){
            
            if(mp.count(s[i]) == 1){//如果当前字符已经在当前子串出现过了
                // res = max(res, end_index - start_index + 1);
                start_index = max(mp[s[i]] + 1, start_index);//例如abba，首先出现的重复字符是b,这个时候的起始位置已经变为2，接下来遍历到a时，如果取mp[s[i]] + 1,则是1，所以每次取起始位置时需要取起始位置的较大者
            }
            
            mp[s[i]] = i;//存储s[i]对应的下标
            end_index = i;
            res = max(res, end_index - start_index + 1);
        }
        // res = max(res, end_index - start_index + 1);
        return res;
    }
};

int main(){
    string s = "abcabcbb";//sdfijgkjs";
    Solution s1;
    cout<<s1.lengthOfLongestSubstring2(s);
}