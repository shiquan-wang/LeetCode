#include<iostream>
#include<ListNode.h>
#include<unordered_set>

using namespace std;
/* 
给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

//快慢指针，一个移动两位，一个移动一位，当两者相遇时存在环
 */
class Solution{
public:
    ListNode *detectCycle(ListNode *head){//快慢指针可以验证是否存在环，无法确定环的入口
        ListNode *temp = new ListNode();
        temp->next = head;
        
        ListNode *slow = temp->next;
        ListNode *fast = temp->next;

        while (fast != nullptr)
        {
            slow = slow->next;
            if(fast->next == nullptr){
                return nullptr;
            }
            fast = fast->next->next;
            if(fast == slow){
                ListNode *pre = temp->next;
                while (pre != slow)
                {
                    pre = pre->next;
                    slow = slow->next;
                }
                return pre;
                
            }
        }

        return nullptr;
        
    }

    ListNode *detectCycle2(ListNode *head){//哈希表
        ListNode *temp = new ListNode();
        temp->next = head;
        unordered_set<ListNode*> set;
        ListNode *node = temp;

        while (node->next != nullptr)
        {
            if(set.find(node->next) != set.end()){
                return node->next;
            }
            set.insert(node->next);
            node = node->next;
        }
        return nullptr;
    }
};