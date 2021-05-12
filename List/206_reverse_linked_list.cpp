#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0),next(nullptr){};
    ListNode(int x) : val(x),next(nullptr){};
    ListNode(int x,ListNode *next) : val(x),next(next){};
};

class Solution{
    private:

    public:
    /* 迭代法，在遍历链表时，将当前节点的 \textit{next}next 指针改为指向前一个节点。由于节点没有引用其前一个节点，因此必须事先存储其前一个节点。在更改引用之前，还需要存储后一个节点。最后返回新的头引用。
    空间O(1)  时间O(n)
     */
    ListNode* reverseList1(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    /* 头插法，遍历链表将其元素头插法插入新的链表中  空间O(1) 时间O(n)*/ 
    ListNode *reverseList2(ListNode *head){
        ListNode *temp = nullptr;
        while(head){
            temp = new ListNode(head->val,temp);
            head = head->next;
        }
        return temp;
    }

    /* 递归法， */
};

int main(){
    int a[] = {1,2,3,4,5};
    ListNode *head = nullptr;
    for(int i = 4; i>=0; --i){
        head = new ListNode(a[i], head);
    }
    Solution s ;
    ListNode *reverse = s.reverseList2(head);
    while(reverse){
        cout<<reverse->val<<endl;
        reverse = reverse->next;
    } 
}
