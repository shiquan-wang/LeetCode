#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<typeinfo>
using namespace std;

class Solution
{
private:
    /* data */
public:
    Solution(/* args */);
    ~Solution();
    int longestPalindrome(string s){//贪心法， 遍历整个字符串，对于字符数为偶数的字符长度加该字符的字符总数，如果总个数为奇数，则整除2再乘2，遇到第一个奇数个的字符，长度加1。
        map<char, int> m;
        int ans = 0, flag = 0;
        for(char c : s){
            m[c]++;
        }
        // for(auto i : m){
        //     if(i.second % 2 == 1){
        //         flag = 1;
        //     }
        //     ans += i.second/2*2;
        // }
//点运算符“.”应用于实际的对象，箭头运算符“->”与一个指针对象的指针一起使用
        map<char, int> :: iterator iter;
        iter = m.begin();
        cout<<typeid(iter).name();
        while(iter != m.end()){
            if(iter->second %2 == 1){
                flag = 1;
            }
            ans += iter->second/2*2;
        }

        ans += flag;
        return ans;
    }
};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}

int main(){
    string s = "aabbccdc";
    Solution s1;
    cout<<s1.longestPalindrome(s);
}