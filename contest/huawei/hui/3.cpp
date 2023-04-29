#include<iostream>
#include<string>
#include<stack>
#include<unordered_map>
using namespace std;

class Solution{
public:
    int pos;
    int compute(string & data)
    {
        int len = data.length();
        int num = 0;
        char flag = '+';
        stack<int> st;
 
        while (pos < len) {
            if (data[pos] == '{' || data[pos] == '[' || data[pos] == '(') {
                pos++;
                num = compute(data);
            }
 
            while (pos < len && isdigit(data[pos])) {
                num = num * 10 + data[pos] -'0';
                pos++;
            }
 
            switch (flag) {
            case '+':
                st.push(num);
                break;
            case '-':
                st.push(-num);
                break;
            case '*':
                {
                    int temp = st.top();
                    temp *= num;
                    st.pop();
                    st.push(temp);
                    break;
                }
            case '/':
                {
                    int temp = st.top();
                    temp /= num;
                    st.pop();
                    st.push(temp);
                    break;
                }
            }
 
            num = 0;
            flag = data[pos];
            if (data[pos] == '}' || data[pos] == ']'|| data[pos] == ')') {
                pos++;
                break;
            }
            pos++;
        }
 
        int sum = 0;
        while (st.size()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};
int main(){
    string data;
    cin>>data;
    int n;
    cin>>n;
    if(n == 10){
        Solution s1;
        s1.pos = 0;
        cout<<s1.compute(data);
    }
    unordered_map<char, int> up = {{'-',1}, {'+', 1}, {'*', 2}, {'/', 2}, {'%', 2}};
}