#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/* 
题目描述：给定两个 01 字符串 a 和 b ，请计算它们的和，并以二进制字符串的形式输出。输入为 非空 字符串且只包含数字 1 和 0。
解题思路：模仿十进制加法的运算过程，将a与b使用reverse函数进行反转，从首位开始进行运算，carry用来统计进位，
贴士：size_t 跨平台 a.at(i) 进行越界检查，会有性能损耗
 */
class Solution{
public:
    string addBinary(string a, string b){
        string res;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int n = max(a.size(), b.size()), carry = 0;
        for(size_t i = 0; i < n; ++i){
            carry += i < a.size() ? (a.at(i) == '1') : 0;
            carry += i < b.size() ? (b.at(i) == '1') : 0;
            res.push_back((carry%2) ? '1' : '0');
            carry /= 2;
        }

        if(carry){
            res.push_back('1');
        }
        reverse(res.begin(), res.end());

        return res;
    }
};

int main(){
    string a = "10", b ="11";
    Solution s1;
    cout<<s1.addBinary(a, b);
}