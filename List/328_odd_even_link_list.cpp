#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

class Solution
{
private:
    /* data */
public:
    Solution(/* args */);
    ~Solution();
    ListNode *oddEvenList(ListNode *head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *oddhead = head, *evenhead = head->next; //oddhead 是奇数结点头结点， evenhead 是偶数结点头结点
        ListNode *odd = oddhead, *even = evenhead; //双指针进行链表遍历同时分离奇偶位置的结点
        while(even && even->next){ //奇偶指针后移
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenhead;
        return oddhead;
    }
};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}

int main(){
    int a[] = {1, 2, 3, 4, 5};
    ListNode *head = new ListNode(a[0]);
    ListNode *tail = head;
    for(int i =1;i<5; ++i){
        ListNode *temp = new ListNode(a[i]);
        tail->next = temp;
        tail = tail->next;
    }
    ListNode *t = head;
    while(t){
        cout<<t->val;
        t = t->next;
    }
    Solution s;
    ListNode *res =  s.oddEvenList(head);
    while(res){
        cout<<res->val;
        res = res->next;
    }

}