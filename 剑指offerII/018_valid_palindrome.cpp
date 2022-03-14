#include<iostream>
#include<string>
#include<vector>

using namespace std;
/* 
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
输入: "A man, a plan, a canal: Panama"
输出: true
解释："amanaplanacanalpanama" 是回文串


 */
class Solution{
public:
    bool isPalindrome(string s){
        if(s.length() == 0) return true;
        for(int l = 0, r = s.length() - 1; l < r;){//48 - 57 数字 65-90 大写字母 97-122小写字母
            while(!isalnum(s[l]) && l<r){//s[l]是其他字符，l右移找到第一个英文字符或者数字 (!islower(s[l]) && !isupper(s[l]) && !isdigit(s[l])) == !isnum(s[l])
                ++l;
            }

            while(!isalnum(s[r]) && l<r){//s[r]其他字符，r左移找到第一个英文字符或者数字 (!islower(s[r]) && !isupper(s[r]) && isdigit(s[r])) == !isnum(s[r])
                --r;
            }

            if(l < r){//
                if(tolower(s[l]) != tolower(s[r])){
                return false;
                }else{
                    ++l, --r;
                }
            }
            
        }
        return true;
    }
};

int main(){
    Solution s1;
    //cout<<s1.isPalindrome("A man, a plan, a canal: Panama");
    cout<<s1.isPalindrome("race a car");
   // cout<<s1.isPalindrome("");
}