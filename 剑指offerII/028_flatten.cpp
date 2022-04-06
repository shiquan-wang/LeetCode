#include<iostream>
#include<vector>

using namespace std;
/* 
多级双向链表中，除了指向下一个节点和前一个节点指针之外，它还有一个子链表指针，可能指向单独的双向链表。这些子列表也可能会有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。

给定位于列表第一级的头节点，请扁平化列表，即将这样的多级双向链表展平成普通的双向链表，使所有结点出现在单级双链表中

//思路：递归
 */
class Node{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution{
private:
    Node *dfs(Node *head){
        Node *cur = head;
        Node *last = nullptr;

        while (cur)
        {
            Node *next = cur->next;
            if(cur->child != nullptr){
                Node *child_last = dfs(cur->child);

                next = cur->next;
                cur->next = cur->child;
                cur->child->prev = cur;

                if(next != nullptr){
                    child_last->next = next;
                    next->prev = child_last;
                }

                cur->child = nullptr;
                last = child_last;
            }else{
                last = cur;
            }
            cur = next;
        }
        return last;
        
    }
public:

    Node *flatten(Node *head){
        
        dfs(head);
        return head;

    }
};