#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
    public:
        bool isAnagram(string s, string t){
            if(s.length() != t.length())
                return false;
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            return s == t;
        }
        // bool isAnagram2(string s, string t){
        //     if(s.length()!=t.length())
        //         return false;
        //     vector<int> table(26, 0);
        //     string ::iterator iterable;
        //     iterable = s.begin();
        //     while(iterable != s.end()){
        //         int index = iterable - 'a';
        //         table[iterable-'a']++;
        //         iterable++;
        //     };

};

int main(){
    string s = "sugar";
    string t = "ugars";
    Solution s1;
    cout<<s1.isAnagram(s, t);
}