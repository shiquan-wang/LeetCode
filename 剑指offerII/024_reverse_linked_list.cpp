#include<iostream>
#include<ListNode.h>

using namespace std;

class Solution{
public:
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr)
        {
           ListNode* next = curr->next;
           curr->next = prev;
           prev = curr;
           curr = next;
        }
        return prev;
    }
};