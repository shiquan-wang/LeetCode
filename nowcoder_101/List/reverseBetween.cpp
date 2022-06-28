#include<iostream>
#include"ListNode.h"

using namespace std;
/* 
将一个节点数为 size 链表 m 位置到 n 位置之间的区间反转，要求时间复杂度 O(n)O(n)，空间复杂度 O(1)O(1)。
例如：
给出的链表为 1\to 2 \to 3 \to 4 \to 5 \to NULL1→2→3→4→5→NULL, m=2,n=4m=2,n=4,
返回 1\to 4\to 3\to 2\to 5\to NULL1→4→3→2→5→NULL.

数据范围： 链表长度 0 < size \le 10000<size≤1000，0 < m \le n \le size0<m≤n≤size，链表中每个节点的值满足 |val| \le 1000∣val∣≤1000
要求：时间复杂度 O(n)O(n) ，空间复杂度 O(n)O(n)
进阶：时间复杂度 O(n)O(n)，空间复杂度 O(1)O(1)
 */
class Solution{
public:
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr)
        {
            /* code */
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n){
        ListNode* dummyNode = new ListNode();//因为是链表中间操作而且链表长度可能是1，所以构造一个虚拟头结点，可以不用额外的判断操作
        dummyNode->next = head;

        ListNode* pre = dummyNode;
        for(int i = 0; i < m-1; ++i){//从虚拟节点走m-1步，pre到达left节点的前一个节点
            pre = pre->next;
        }

        ListNode* rightNode = pre;
        for(int i = 0; i < n-m+1; ++i){//从pre节点走n-m+1步，到达right节点
            rightNode = rightNode->next;
        }

        ListNode* leftNode = pre->next;//切断左边节点的联系
        pre->next = nullptr;

        ListNode* curr = rightNode->next;//切断右边节点的联系
        rightNode->next = nullptr;

        reverse(leftNode);//反转leftnode - rightnode区间

        pre->next = rightNode;//接回到原来的链表中
        leftNode->next = curr;

        return dummyNode->next;
        /* 
        需要遍历两边链表，
         */
    }
    ListNode* reverseBetween(ListNode* head, int m, int n){
        //一次遍历，反转链表
        //整体思想是：在需要反转的区间里，每遍历到一个节点，让这个新节点来到反转部分的起始位置。
        //curr：指向待反转区域的第一个节点 left；
        //next：永远指向 curr 的下一个节点，循环过程中，curr 变化以后 next 会变化；
        //pre：永远指向待反转区域的第一个节点 left 的前一个节点，在循环过程中不变。

        ListNode *dummpyNode = new ListNode();
        dummpyNode->next = head;
        ListNode *pre = dummpyNode;

        for(int i = 0; i < m-1; ++i){
            pre = pre->next;
        }

        ListNode *curr = pre->next;
        ListNode *next;
        for(int i = 0; i < n-m; ++i){
            next = curr->next;
            curr->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return dummpyNode->next;
    }

};