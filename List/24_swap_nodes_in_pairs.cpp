#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

class Solution{
    public:
    /*1->2->3   》》2->1->3
    temp = 2
    1->next = swap(2->next)
    temp->next = 1
     */
    ListNode* swapPairs(ListNode *head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *temp = head->next;
        head->next = swapPairs(temp->next);
        temp->next = head;
        return temp;
    }
    /*迭代   */
    ListNode* swapPairs_iteration(ListNode *head){
        ListNode *dummpy = new ListNode();
        dummpy->next = head;
        ListNode *temp = dummpy;
        /* 
        如果 temp 的后面没有节点或者只有一个节点，则没有更多的节点需要交换，因此结束交换。否则，
        获得 temp 后面的两个节点 node1 和 node2，通过更新节点的指针关系实现两两交换节点。
        具体而言，交换之前的节点关系是 temp -> node1 -> node2，交换之后的节点关系要变成 temp -> node2 -> node1，

        
        */
        while(temp->next && temp->next->next){
            ListNode *node1 = temp->next;
            ListNode *node2 = temp->next->next;
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
        }
        return dummpy->next;
    }
};

int main(){
    int a[] = {1, 2, 3, 4};
    ListNode *head = new ListNode(1);
    ListNode *tail = head;
    for(int i = 1; i<4; ++i){
        ListNode *temp = new ListNode(a[i]);
        tail->next = temp;
        tail = tail->next;
    }
    Solution s;
    head = s.swapPairs(head);
    while(head){
        cout<<head->val<<endl;
        head = head->next;
    }
}