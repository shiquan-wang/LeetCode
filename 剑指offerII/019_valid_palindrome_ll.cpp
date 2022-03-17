#include<iostream>
#include<vector>

using namespace std;

/* 
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串

 */
class Solution{
private:
    bool res = true;
    bool is_Palidrome(string s, int left, int right){
        
        for(int l = left, r = right; l < r; ++l, --r){
            if(s[l] != s[r]){
                return false;
            }
        }
        return true;
    }
    bool is_Palidrome2(string s, int left, int right){
        for(int l = left, r = right; l < r; ++l, --r){
            if(s[l] == s[r]){
                continue;
            }else if(s[l] != s[r] && res == true){//这里需要使用一个标志位来确保只能进入一次删除字符的递归， 如果不加这个标志位则每次遇到不同字符都会进入删除字符的递归
                res = false;
                return is_Palidrome2(s, l, r-1)|| is_Palidrome2(s, l+1, r);
            }else{
                return false;
            }
        }
        return true;
    }
public:
    bool validPalindrome(string s){
        int n = s.length();
        int l = 0, r = n-1;
        
        /* while (l < r)
        {
            if(s[l] == s[r]){
                ++l; --r;
            }else{
                return is_Palidrome(s, l, r-1) || is_Palidrome(s, l+1, r);
            }   
        }
        return true; */
        return is_Palidrome2(s, l, r);
    }
};

int main(){
    Solution s1;
    cout<<s1.validPalindrome("abc");
}
