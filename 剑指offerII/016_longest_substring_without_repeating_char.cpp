#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution{
public:
    int lengthOfLongestSubstring(string s){
        //思路没有问题，执行出错，因为包含s包含空格数字和符号，需要使用set或者map来存储窗口内字符
        int n = s.length();
        vector<char> cnt(26, 0);
        int res = 0, temp = 0;
        for(int left = 0, right = 0; right < n; ){
            if(cnt[s[right] - 'a'] == 0){//当前窗口不存在s[right]字符
                ++cnt[s[right] - 'a'];
                ++right;
            }else{
                while (cnt[s[right] - 'a'] != 0)
                //当前窗口存在s[right]字符,不断左移left指针使得子序列不存在重复元素
                {
                    --cnt[s[left] - 'a'];
                    ++left ;
                }
            }
            res = max(res, right - left);
        }
        return res;
    }
    int lengthOfLongestSubstring2(string s){
        
        int n = s.length();
        unordered_map<char, int> map;
        //存储字符及其下标，每个字符只会出现一次，所以不用存储次数，只需要使用map.find() 来看是否存在某一个元素即可
        //!!! 需要一个标志位来判断当前的起始位置，c++不好实现，可以用python或者不使用map,使用set
        int res = 0;
        for(int left = 0, right = 0; right < n; ){
            if(map.find(s[right]) != map.end()){//s[right]在当前窗口不重复
                map[s[right]] = right;//存储字符及其下标
                ++right;
            }else{//s[right]在当前窗口中已存在
                left = map[s[right]]+1;
                map[s[right]] = right;
            }
            res = max(res, right - left);
        }
        return res;
    }
    int lengthOfLongestSubstring3(string s){
        int n = s.length();
        unordered_set<char> set;
        int res = 0;

        for(int left = 0, right = 0; right < n;){
            if(set.find(s[right]) != set.end()){
                while (set.find(s[right]) != set.end())
                {
                    set.erase(s[left]);
                    ++left;
                }
                
            }else{
                set.insert(s[right]);
                ++right;
            }
            res = max(res, right - left);
        }
        return res;
    }
};

int main(){
    Solution s1;
    cout<<s1.lengthOfLongestSubstring3("abcabcbb");
}