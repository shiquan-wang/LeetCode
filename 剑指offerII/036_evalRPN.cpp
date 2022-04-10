#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;
/* 
根据 逆波兰表示法，求该后缀表达式的计算结果。
有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
输入：tokens = ["2","1","+","3","*"]
输出：9
解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9

字符串转数字 ：
string s = "101";
int res = atoi(s.c_str());
数字转字符串
int temp = 1234;
strign s = to_string(temp);

 */

/* 
一定要先判断数字，不能用s[0]先判断是否是运算符号，因为-11的第一位也是运算符号。 */
class Solution{
public:
    int evalRPN(vector<string>& tokens){
        stack<int> st;
        for(string s : tokens){
            if(isNumber(s)){
                st.push(atoi(s.c_str()));
            }else{
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                switch (s[0])
                {
                case '+': st.push(num1 + num2); break;
                case '-': st.push(num1 - num2); break;
                case '*': st.push(num1 * num2); break;
                case '/': st.push(num1 / num2); break;
                default:
                    break;
                }
            }
        }

        return st.top();
    }
    bool isNumber(string& token){//判断字符串是否是数字
        // return !(token == "+" || token == "-" || token == "*" || token == "/");
        if(token.size() > 1) {//token 长度大于1定是数字
            return true;
        }else if(token[0] != '+' && token[0] != '-' && token[0] != '*' && token[0] != '/'){//长度是1,判断是否是运算符号
            return true;
        }
        return false;
    }
    
};

int main(){
    string s = "101";
    Solution s1;
}