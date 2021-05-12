#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0),next(nullptr){}
    ListNode(int x) : val(x),next(nullptr){}
    ListNode(int x,ListNode *next) : val(x),next(next){}
};

class Solution{
    public:
    /* 合并两个有序链表 迭代 */
    ListNode* mergeTwoLists(ListNode *l1,ListNode *l2){
        ListNode *temp = new ListNode();
        ListNode *prev = temp;
        while(l1 && l2){
            if(l1->val < l2->val){
                temp->next = l1;
                l1 = l1->next;
            }else{
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        temp->next = l1 == nullptr ? l2->next : l1->next;
        return prev->next;
    } 
};

int main(){
    int a[] = {1,2,3,4};
    int b[] = {1,2,4};
    ListNode *l1 = new ListNode();
    ListNode *l2 = new ListNode();
    ListNode *tail = l1;
    for(int i = 0; i<4; i++){
        ListNode *temp = new ListNode(a[i]);
        tail->next = temp;
        tail = tail->next;
    }
    for(int i = 0;i<4;++i){
        cout<<l1->next->val;
        l1 = l1->next;
    }
}