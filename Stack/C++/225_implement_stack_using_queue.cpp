#include <iostream>
#include <queue>
using namespace std;

class MyStack{
    private:
    queue<int> q1,q2;

    public:
    MyStack(){

    }

    void push(int x){               //每次入栈时，先将q1中数据存放在q2中，入栈元素入q1，再将q2元素入q1。从而实现pop元素时后进先出。
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop(){
        int temp = q1.front();
        q1.pop();
        return temp;
    }

    int top(){
        return q1.front();
    }

    bool empty(){
        return q1.empty();
    }

};

int main(){
    MyStack mystack;
    mystack.push(1);
    mystack.push(2);  
    cout<<mystack.top()<<endl;  
    cout<<mystack.pop()<<endl;
    cout<<mystack.empty()<<endl;

}