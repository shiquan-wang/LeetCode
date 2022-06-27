#include<iostream>
#include"ListNode.h"

using namespace std;

class Solution{
public:
    ListNode* reverse_list(ListNode* head){//迭代法
        if(head == nullptr) return head;
        ListNode *curr = head;
        ListNode *pre = nullptr;

        while (curr)
        {
            ListNode *temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = temp;
        }
        
        return pre;
    }
    ListNode* reverse_list2(ListNode* pHead){//递归法
        if(pHead == nullptr || pHead->next == nullptr){
            return pHead;
        }
        ListNode* temp = reverse_list2(pHead->next);

        pHead->next->next = pHead;
        pHead->next = nullptr;
        return temp;
    }
};