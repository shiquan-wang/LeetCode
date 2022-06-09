#include <iostream>
#include<vector>
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
    /* 迭代法，在遍历链表时，将当前节点的 next 指针改为指向前一个节点。由于节点没有引用其前一个节点，因此必须事先存储其前一个节点。在更改引用之前，还需要存储后一个节点。最后返回新的头引用。
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
    ListNode* reverseList3(ListNode* head){
        if(head == nullptr || head->next == nullptr){//如果head为空说明链表本身为空，否则当head->next为空时说明遍历到链表的最后一个元素即反转后的头结点位置了，停止递归，返回新的头结点
            return head;
        }

        ListNode* temp = reverseList3(head->next);

        head->next->next = head;
        head->next = nullptr;
        return temp;
    }
    /* 举例 1->2->3->nullptr
    递归过程：
    1入栈 temp = reverse(2->3)
    2入栈 temp = reverse(3)
    3入栈 3->next = nullptr 返回3
    2入栈时 temp = 3, head = 2, 因此 2->next->next = 2 => 3->next = 2, 2->next = nullptr; 链表状态 3->2->nullptr; 返回temp = 3
    1入栈时 temp = reverse(2->3) = 3, 1->next->next = 1 => 2->next = 1; 1->next = nullptr; return 3
    递归结束 */

};

int main(){
    // int a[] = {1,2,3,4,5};
    // int n;
    // cin>>n;
    int item;
    vector<int> vec;
    char ch;
    // while (cin>>item)
    // {
    //     vec.push_back(item);
    // }
    while (1)
    {
        cin>>item;
        vec.push_back(item);
        if(cin.get() == '\n'){
            break;
        }
    }
    // do{
    //     cin>>item;
    //     vec.push_back(item);
    // }while (getchar() != '\n');
    
    
    

    ListNode *head = nullptr;
    for(int i = 4; i>=0; --i){
        head = new ListNode(vec[i], head);
    }
    Solution s ;
    ListNode *reverse = s.reverseList2(head);
    while(reverse){
        cout<<reverse->val<<endl;
        reverse = reverse->next;
    } 
}
