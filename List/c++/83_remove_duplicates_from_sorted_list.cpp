#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
    public:
    ListNode* deleteDuplicates(ListNode *head){
        ListNode *cur = head;
        if(!head){
            return head;
        } 
        while(cur->next != nullptr){
            if(cur->val == cur->next->val){
                cur->next = cur->next->next;
            }else{
                cur = cur->next;
            }
        }
        return head;
    }
};

int main(){
    int a[] = {1,1,2,3,3};
    ListNode *head = new ListNode(a[4]);
    for(int i = 3; i>=0; --i){
        head = new ListNode(a[i],head);
    }
    Solution s;
    head = s.deleteDuplicates(head);
    while(head != nullptr){
        cout<<head->val;
        head = head->next;
    }
}