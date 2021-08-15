#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};

class Solution
{
private:
    /* data */
public:
/* 双指针法，考虑构建两个节点指针 A​ , B 分别指向两链表头节点 headA , headB ，做如下操作：

指针 A 先遍历完链表 headA ，再开始遍历链表 headB ，当走到 node 时，共走步数为：a + (b - c)   （node为公共节点

指针 B 先遍历完链表 headB ，再开始遍历链表 headA ，当走到 node 时，共走步数为：b + (a - c)

此时指针 A , B 重合，a + (b - c) = b + (a - c) 有两种情况

若两链表 有 公共尾部 (即 c > 0) ：指针 A , B 同时指向「第一个公共节点」node 。
若两链表 无 公共尾部 (即 c = 0) ：指针 A , B 同时指向 null。
*/
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){   
        ListNode *A = headA;ListNode *B = headB;
        while(A != B){       
            A = A == NULL ? A->next : headB;
            B = B == NULL ? B->next : headA;
        }
        return A;
    }
};

int main(){
    int a[] = {4,1,8,4,5};
    int b[] = {5,6,1,8,4,5};
    ListNode *headA = nullptr,*headB = nullptr;

    for(int i=4; i>=0; --i){
        headA = new ListNode(a[i],headA);
    }
    for(int i = 5; i>=0; --i){
        headB = new ListNode(b[i],headB);
    }
    Solution s;
    ListNode* intersection = s.getIntersectionNode(headA,headB);
    cout<<intersection->val;
    cout<<intersection;
}
