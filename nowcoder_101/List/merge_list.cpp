#include<iostream>
#include"ListNode.h"

using namespace std;

class Solution{
public:
    ListNode* mergeTwoList(ListNode* list1, ListNode* list2){
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = nullptr;

        ListNode* curr = dummyNode;
        while (list1 != nullptr && list2 != nullptr)
        {
            if(list1->val < list2->val){
                curr->next = list1;
                list1 = list1->next;
            }else{
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        if(list1 != nullptr){
            curr->next = list1;
        }

        if(list2 != nullptr){
            curr->next = list2;
        }
        
        return dummyNode->next;
    }
};