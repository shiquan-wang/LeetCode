#include<iostream>
#include<ListNode.h>
#include<stack>
#include<vector>
using namespace std;

class Solution{
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        stack<int> s1, s2;//使用两个栈存储l1 和 l2中每一位的数字
        ListNode* temp = new ListNode();
        temp = l1;
        while(temp != nullptr){
            s1.push(temp->val);
            temp = temp->next;
        }
        temp = l2;
        while (temp != nullptr)
        {
            s2.push(temp->val);
            temp = temp->next;
        }

        ListNode* res = new ListNode();
        int sum = 0, mid = 0;//sum保存当前位值，mid保存进位值
        while (!s1.empty() && !s2.empty())
        {
            int temp_sum = s1.top() + s2.top();
            sum = (temp_sum + mid)%10;//当前位的值
            mid = (temp_sum + mid)/10;//进位的值
            s1.pop(); s2.pop();

            ListNode* temp_node  = new ListNode(sum);
            temp_node->next = res->next;
            res->next = temp_node;
        }

        while (!s1.empty())
        {
            sum = (s1.top() + mid)%10;
            mid = (s1.top() + mid)/10;
            s1.pop();

            ListNode* temp_node  = new ListNode(sum);
            temp_node->next = res->next;
            res->next = temp_node;
        }

         while (!s2.empty())
        {
            sum = (s2.top() + mid)%10;
            mid = (s2.top() + mid)/10;
            s1.pop();

            ListNode* temp_node  = new ListNode(sum);
            temp_node->next = res->next;
            res->next = temp_node;
        }
        if(mid != 0){
            ListNode* temp_node  = new ListNode(mid);
            temp_node->next = res->next;
            res->next = temp_node;
        }
        
        return res->next;
        
    }
};

int main(){
    vector<int> l1 = {0}, l2 = {7, 3};
    
}