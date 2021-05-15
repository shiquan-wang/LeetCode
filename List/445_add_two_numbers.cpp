#include <iostream>
#include <stack>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}

};

class Solution{
    public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
        stack<ListNode*> s1, s2;
        ListNode *temp = nullptr;
        while(l1){
            s1.push(l1);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2);
            l2 = l2->next;
        }
        int carry = 0;//进位
        while (!s1.empty() || !s2.empty() || carry != 0)
        {
            int a = s1.empty() ? 0 : s1.top()->val; 
            int b = s2.empty() ? 0 : s2.top()->val; 
            int t = a + b + carry;
            int sum = t % 10;
            carry = t / 10;
            temp = new ListNode(sum,temp);
            if (!s1.empty()){
                s1.pop();
            } 
            if(!s2.empty()){
                s2.pop();
            }
        }
        return temp;
    }
};

int main(){
    int a[] = {7, 2, 4, 3};
    int b[] = {5, 6, 4};
    ListNode *l1 = new ListNode(7);
    ListNode *l2 = new ListNode(5);
    ListNode *tail = l1;
    for(int i = 1; i<4; ++i){
        ListNode *temp = new ListNode(a[i]);
        tail->next = temp;
        tail = tail->next;
    }
    
    tail = l2;
    for(int i = 1; i<3;++i){
        ListNode *temp = new ListNode(b[i]);
        tail->next = temp;
        tail = tail->next;
    }
    
    Solution s;
    ListNode *temp = s.addTwoNumbers(l1, l2);
    while(temp){
        cout<<temp->val;
        temp = temp->next;
    }  
}