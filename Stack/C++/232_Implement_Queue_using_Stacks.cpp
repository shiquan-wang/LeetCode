#include <iostream>
#include <stack>
using namespace std;


class MyQueue{
    private:
    stack<int> s1,s2;

    public:
    MyQueue(){
       
    }

    void push(int t){                 //入队；入s1
        s1.push(t);
    }

    int pop(){                       //pop and return queue first element；  s2空,s1出栈到s2，s2出栈；  s2非空，s2出栈
        int temp;
        if(s2.empty() && !(s1.empty())){
            while(!s1.empty()){
                temp = s1.top();
                s2.push(temp);
                s1.pop();
            }
        }
        temp = s2.top();
        s2.pop();
        return temp;
    }

    int peek(){                     //return the first element from queue;   s2非空，返回s2.top()否则s1数据转入s2，再返回
        int temp;
        if(s2.empty()){
            while(!s1.empty()){
                temp = s1.top();
                s2.push(temp);
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty(){                    //retrun queue is empty
        if(s1.empty() && s2.empty()){
            return true;
        }else return false;
    }
};

int main(){
    MyQueue q;
    q.push(1);
    cout<<q.pop();
    q.push(2);
    cout<<q.pop();
    q.peek();
    q.pop();
    
   
}