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
    /* 
    双指针（快慢指针），快指针先走n+1个位置，然后两个指针同时前行直到快指针遍历完整个链表，
    这时候满指针的下一个元素就是倒数第N个元素。代码为不带头结点的链表代码，
     */
    ListNode* removeNthFromEnd(ListNode *head, int n){
        ListNode *dummpy = new ListNode();
        dummpy->next =head;
        ListNode *quick = dummpy;
        ListNode *slow = dummpy;
        for(int i = 0; i<n; ++i){ //quick 前进n个节点
            quick = quick->next;
        }
        while(quick->next != nullptr){
            quick = quick->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummpy->next;    //不能使用 return head; 不带头结点的代码，要返回dummpy的下一个节点，因为head节点有可能是被删除的节点
    }
};

int main(){
    int a[] = {1,2,3,4,5};
    ListNode *head = new ListNode(1); //不带头结点
    ListNode *tail = head;
    for(int i = 1; i<5; ++i){
        ListNode *temp = new ListNode(a[i]);
        tail->next = temp;
        tail = tail->next;
    }
    Solution s;
    head = s.removeNthFromEnd(head, 2);
    while(head){
        cout<<head->val<<endl;
        head = head->next;
    }

}