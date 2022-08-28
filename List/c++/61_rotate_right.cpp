/* 
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置
 */
#include"ListNode.h"
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k == 0 || head->next == nullptr) return head;
        int n = 0;
        ListNode* num = head;
        while(num != nullptr){
            num = num->next;
            n++;
        }
        
        k = k%n;
        if(k == n || k == 0) return head;

        ListNode* fast = head;
        ListNode* slow = head;
        for(int i = 0; i < k; ++i){
            fast = fast->next;
        }
        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = nullptr;
        fast->next = head;
        return temp;
    }
};