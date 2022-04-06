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
    ListNode *NthForENd(ListNode *head, int len){
        ListNode *temp = new ListNode();
        temp->next = head;
        ListNode *fast = temp;
        ListNode *slow = temp;

        for(int i = 0; i < len; ++i){//快指针先移动len位
            fast = fast->next;
        }

        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        return slow;
    }
public:
    ListNode *getIntersectionNode_error(ListNode *headA, ListNode *headB){//快慢指针思路错误，
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

        ListNode *tempA = NthForENd(headA, len);
        ListNode *tempB = NthForENd(headB, len);
        

        if(tempA == tempB){
            return tempA;
        }else{
            return nullptr;
        }
    }
    /* 
只有当链表 headA 和 headB 都不为空时，两个链表才可能相交。因此首先判断链表 headA 和 headB 是否为空，如果其中至少有一个链表为空，则两个链表一定不相交，返回 null。

当链表 headA 和 headB 都不为空时，创建两个指针 pA 和pB，初始时分别指向两个链表的头节点 headA 和headB，然后将两个指针依次遍历两个链表的每个节点。具体做法如下：

每步操作需要同时更新指针 pA 和 pB。

如果指针 pA 不为空，则将指针 pA 移到下一个节点；如果指针 pB 不为空，则将指针 pB 移到下一个节点。

如果指针 pA 为空，则将指针pA 移到链表 headB 的头节点；如果指针 pB 为空，则将指针pB 移到链表headA 的头节点。

当指针 pA 和 pB 指向同一个节点或者都为空时，返回它们指向的节点或者 null。


证明

下面提供双指针方法的正确性证明。考虑两种情况，第一种情况是两个链表相交，第二种情况是两个链表不相交。

情况一：两个链表相交

链表headA 和 headB 的长度分别是 m 和 n。假设链表 headA 的不相交部分有 a 个节点，链表 headB 的不相交部分有 b 个节点，两个链表相交的部分有 c 个节点，则有 a+c=m，b+c=n。

如果 a=b，则两个指针会同时到达两个链表相交的节点，此时返回相交的节点；

如果 a != b，则指针 pA 会遍历完链表 headA，指针 pB 会遍历完链表 headB，两个指针不会同时到达链表的尾节点，然后指针 pA 移到链表 }headB 的头节点，指针 pB 移到链表headA 的头节点，然后两个指针继续移动，
指针pA 移动了 a+c+b 次、指针 pB 移动了 b+c+a 次之后，两个指针会同时到达两个链表相交的节点，该节点也是两个指针第一次同时指向的节点，此时返回相交的节点。

情况二：两个链表不相交

链表 headA 和 headB 的长度分别是 m 和 n。考虑当 m=n 和 m != n 时，两个指针分别会如何移动：

如果 m=n，则两个指针会同时到达两个链表的尾节点，然后同时变成空值 null，此时返回 null；

如果 m != n，则由于两个链表没有公共节点，两个指针也不会同时到达两个链表的尾节点，因此两个指针都会遍历完两个链表，在指针 pA 移动了 m+n 次、指针pB 移动了 n+m 次之后，
两个指针会同时变成空值null，此时返回 null。

     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        if(headA == nullptr || headB == nullptr) return nullptr;

        ListNode *tempA = headA, *tempB = headB;

        while (tempA != tempB)
        {
            if(tempA != nullptr){
                tempA = tempA->next;
            }else{
                tempA = headB;
            }

            if(tempB != nullptr){
                tempB = tempB->next;
            }else{
                tempB = headA;
            }
        }

        /* if(tempA == nullptr){
            return nullptr;
        }else{
            return tempA;
        } */
        return tempA;
        
    }
};
