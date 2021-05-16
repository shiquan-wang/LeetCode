// Given the head of a singly linked list, return true if it is a palindrome. 判断是否存在回文字符串
#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(0), next(next) {}
};

class Solution{
    public:
    //反转后一半链表，比较是否前后相同，
    bool isPalindrome(ListNode *head){
        ListNode *midnode = halfnode(head);
        ListNode *reverselist = reverse(midnode->next); //如果链表为奇数个节点，需要将

        ListNode *p1 = head;
        ListNode *p2 = reverselist;
        bool result= true;
        while(result && p2 != nullptr){
            if(p1->val != p2->val){
                result = false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        midnode->next = reverse(reverselist); //反转后半部分链表
        return result;
        
    }

    ListNode *halfnode(ListNode *head){   //快慢指针寻找到中间节点
        ListNode *fast,*slow;
        fast = slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr){  //边界条件判断
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode *reverse(ListNode *head){   //链表反转
        ListNode *curr = head;
        ListNode *prev = nullptr;
        while(curr){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};

int main(){
    int a[] = {1,0,0};
    ListNode *head = new ListNode(1);
    ListNode *tail =head;
    for(int i = 1;i<3;++i){
        ListNode *temp = new ListNode(a[i]);
        tail->next = temp;
        tail = tail->next;
    }
    Solution s;
    cout<<s.isPalindrome(head);

}