#include<iostream>
#include<string>

using namespace std;
/* 
给你一个 仅 由字符 'a' 和 'b' 组成的字符串  s 。如果字符串中 每个 'a' 都出现在 每个 'b' 之前，返回 true ；否则，返回 false 。
 */
class Solution{
public:
    bool checkString(string s){
        int n = s.size();
        bool res = true;
        for(int i = 0; i < n; ++i){
            if(s[i] == 'b'){
                // res = true;
                for(int j = i; j < n; ++j){
                    if(s[j] == 'a'){
                        res = false;
                        break;
                    }
                }
            }
            // if(s[i] == 'a' && res == true){
            //     res = false;
            //     break;
            // }
            if(res == false) break;
        }
        return res;
    }
};

int main(){
    string s1 = "a";
    Solution s;
    bool res = s.checkString(s1);
    cout<<res;
}