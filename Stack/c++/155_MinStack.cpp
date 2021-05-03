#include <iostream>
#include <stack>
using namespace std;

/* 基本思路： 利用辅助栈，每次元素x入栈s1，将栈内最小元素入栈s2
在元素入栈时将栈内最小元素入辅助栈s2 
元素出栈时辅助栈同时出栈栈顶元素
非同步思路：入栈时新元素小于等于栈顶元素时入栈s2（这里等于是因为当出栈元素和s2栈顶元素相同时二者都出栈）
，出栈时只有当s1出栈元素等于s2栈顶元素时才s2栈顶元素才出栈
*/

class MinStack{
    private:
    stack<int> s1,s2;

    public:
    MinStack(){

    }

    void push(int x){                    
        s1.push(x);
        if(s2.empty() || x < s2.top()){        //x小于s2栈顶元素（s2为空）时，此时栈内最小元素为x，x入栈s2
            s2.push(x);
        }else{
            s2.push(s2.top());
        }
    }
    
    void push_2(int x){
        s1.push(x);
        if(s2.empty()){
            s2.push(x);
        }else{
            if(x <= s2.top()){
                s2.push(x);
            }
        }
    }

    void pop(){
        s2.pop();
        s1.pop();
    }

    void pop_2(){
        int temp = s1.top();
        if(temp == s2.top()){
            s2.pop();
        }
        s1.pop();
    }


    int top(){
        return s1.top();
    }


    int getMin(){
        return s2.top();
    }

};

int main(){
    MinStack s;
    s.push_2(-2);
    s.push_2(0);
    s.push_2(-3);
    cout<<s.getMin()<<endl;
    s.pop_2();
    cout<<s.top()<<endl;
    cout<<s.getMin()<<endl;

}
    