#include<iostream>
#include<ListNode.h>
#include<unordered_set>

using namespace std;
/*
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 
基本思路：首先遍历两个链表，计算出长度差len，然后使用快慢指针找到倒数第i个元素，如果元素相同，则该节点即为相交的起始节点
 */

class Solution{
private:
    ListNode *NthForENd(ListNode *head){
        ListNode *temp = new ListNode();
        temp->next = head;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        int len_A = 0, len_B = 0, len;
        ListNode *temp = new ListNode();

        temp = headA;
        while (temp != nullptr)//计算headA的长度
        {
            len_A++;
            temp = temp->next;
        }

        temp = headB;
        while(temp != nullptr){//计算headB的长度
            len_B++;
            temp = temp->next;
        }

        len = len_A > len_B ? (len_A - len_B) : (len_B - len_A);

        ListNode *slow = new ListNode();
        ListNode *fast = new ListNode();
        ListNode *tempA = new ListNode();
        ListNode *tempB = new ListNode();
        //寻找headA的倒数第len个节点
        slow->next = headA; fast->next = headB;
        for(int i = 0; i < len; ++i){
            fast = fast->next;
        }

        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        tempA = slow;

        slow->next = headB; fast->next = headA;
        for(int i = 0; i < len; ++i){
            fast = fast->next;
        }

        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        tempB = slow;

        if(tempA == tempB){
            return tempA;
        }else{
            return nullptr;
        }
    }
};
