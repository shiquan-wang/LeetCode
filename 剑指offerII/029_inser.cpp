#include<iostream>
#include<vector>

using namespace std;

/* 
给定循环单调非递减列表中的一个点，写一个函数向这个列表中插入一个新元素 insertVal ，使这个列表仍然是循环升序的。

给定的可以是这个列表中任意一个顶点的指针，并不一定是这个列表中最小元素的指针。

如果有多个满足条件的插入位置，可以选择任意一个位置插入新的值，插入后整个列表仍然保持有序。

如果列表为空（给定的节点是 null），需要创建一个循环有序列表并返回这个节点。否则。请返回原先给定的节点。

 */

class Node{
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val){
        val = _val;
        next = nullptr;
    }

    Node(int _val, Node* _next){
        val = _val;
        next = _next;
    }
};

class Solution{
public:
    Node* insert(Node* head, int  insertVal){
        if(head == nullptr){//空链表建立新的循环链表
            head = new Node(insertVal);
            head->next = head;
            return head;
        }

        Node* cur = head;
        while (cur->next != head)//遍历循环单调非递减链表，找到insertVal应该插入的地方
        {
            if(cur->next->val < cur->val){//当前cur是尾结点
                if(cur->next->val >= insertVal) break;//首节点节点值小于insertVal，说明insertVal应该插入尾结点后面首节点前面作为新的首节点。
                else if(cur->val <= insertVal) break;//尾结点小于insertVal，insertVal也是插入链表的最后
            }
            if(cur->val <= insertVal && cur->next->val >= insertVal) break;//cur不是尾结点，
            cur = cur->next;
        }

        cur->next = new Node(insertVal, cur->next);
        return head;
        
    }
};