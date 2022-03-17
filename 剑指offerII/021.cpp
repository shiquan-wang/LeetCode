#include<iostream>
#include<List>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode *temp =  new ListNode();
        temp->next = head;

        ListNode *low = temp;
        ListNode *high = temp;
        
        for(int i = 0; i < n; ++i){
            high = high->next;
        }

        while (high->next != nullptr)
        {
            high = high->next;
            low = low->next;
        }

        //ListNode *temp2 = low->next;
        
        low->next = low->next->next;
        
        

        return temp->next;
    }
};