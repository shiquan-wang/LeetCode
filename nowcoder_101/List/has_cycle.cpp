#include<iostream>
// #include"ListNode.h"

using namespace std;

struct ListNode{
    int val;
    ListNode* next = new ListNode();
    ListNode():val(0), next(nullptr){}
    ListNode(int val):val(val), next(nullptr){}
    ListNode(int val, ListNode* next):val(val), next(next){}
};

class Solution{
public:
    bool hasCycle(ListNode* head){
//判断列表是否有环，使用快慢指针，
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
    }
};