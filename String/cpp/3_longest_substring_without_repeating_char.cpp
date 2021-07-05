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

        for(int i = 0; i < n; ++i){
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
};

int main(){
    string s = "sdfijgkjs";
    Solution s1;
    cout<<s1.lengthOfLongestSubstring(s);
}