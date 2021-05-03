#include <iostream>
#include <stack>
#include <map>
using namespace std;

// class Solution {
// public:
//     bool isValid(string s) {
//         int n = s.size(),top = -1;
//         if(n&2 == 1)
//             return false;
//         char ch[100000];
//         ch[0] = s[0];
//         for(int i = 1;i <= n; i++){
//             if(s[i] == '('||s[i] == '['|| s[i] == '{'){     //左括号入栈，top++
//                 ch[top++] == s[i];
//                 continue;
//             }else{
//                 if(top == -1){                           //右括号且栈空，false
//                     return false;
//                 }
//                 if(s[i] == ')'&&ch[top] == '('){
//                     top--;
//                     continue;
//                 }
//                 if(s[i] == ']'&&ch[top] == '['){
//                     top--;
//                     continue;
//                 }
//                 if(s[i] == '}'&&ch[top] == '{'){
//                     top--;
//                     continue;
//                 }
//             }
//         }
//         if(top == 0){
//             return true;
//         }else{
//             return false;
//         }
//     }
// };

class Solution{
public:
    bool isValid(string s){
        int n = s.size();
        if(n%2 == 1){
            return false;
        }
        map<char,char>pare = {
            {')','('},
            {']','['},
            {'}','{'},

        };
        stack<char> stk;
        for(char c : s){
            if(c ==')'||c == ']'||c == '}'){
                if(stk.empty()){
                    return false;
                }else if(pare[c] == stk.top()){
                    stk.pop();
                }else{
                    return false;
                }
            }else{
                stk.push(c);
            }

        }
        /* if(stk.empty()){
            return true;
        }else{
            return false;
        } */
        return stk.empty();
    }
};

int main(){
    string s = "()[]{}";
    Solution s1;
    cout<<s1.isValid(s);
}