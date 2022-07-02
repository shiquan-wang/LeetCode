#include<iostream>
#include"ListNode.h"

using namespace std;
/* 
步骤分解:
    链表分区为已翻转部分+待翻转部分+未翻转部分
    每次翻转前，要确定翻转链表的范围，这个必须通过 k 此循环来确定
    需记录翻转链表前驱和后继，方便翻转完成后把已翻转部分和未翻转部分连接起来
    初始需要两个变量 pre 和 end，pre 代表待翻转链表的前驱，end 代表待翻转链表的末尾
    经过k此循环，end 到达末尾，记录待翻转链表的后继 next = end.next
    翻转链表，然后将三部分链表连接起来，然后重置 pre 和 end 指针，然后进入下一次循环
    特殊情况，当翻转部分长度不足 k 时，在定位 end 完成后，end==null，已经到达末尾，说明题目已完成，直接返回即可
    时间复杂度为 O(n*K) 最好的情况为 O(n) 最差的情况未 O(n^2)
    空间复杂度为O(1) 除了几个必须的节点指针外，我们并没有占用其他空间

 */
class Solution{
public:
    // ListNode* reverse(ListNode* head){
    //     ListNode* pre = nullptr;
    //     ListNode* cur = head;
    //     while (cur != nullptr)
    //     {
    //         /* code */
    //         ListNode* temp = cur->next;
    //         cur->next = pre;
    //         pre = cur;
    //         cur = temp;
    //     }
    //     return pre;
    // }
    pair<ListNode*, ListNode*> my_reverse(ListNode* head, ListNode* tail){
        ListNode* prev = tail->next;
        ListNode* curr = head;
        while (prev != tail)//curr != tail->next
        {
            /* code */
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return {tail, head};
    }
    ListNode* reverseKGroup(ListNode* head, int k){
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        
        ListNode* pre = dummyNode;

        while (head != nullptr)
        {
            ListNode* tail = pre;//tail指向待反转的k个节点的最后一个节点，
            for(int i = 0; i < k; ++i){
                tail = tail->next;
                if(tail == nullptr){//如果剩余部分长度不足k,则该部分不用反转，直接返回结果
                    return dummyNode->next;
                }
            }

            ListNode* tail_next = tail->next;//保存原链表，
            cout<<tail_next->val;
            pair<ListNode*, ListNode*> result = my_reverse(head, tail);
            head = result.first;
            tail = result.second;
            cout<<head->val<<" "<<tail->val<<endl;
            //接回原来的链表中
            pre->next = head;
            tail->next = tail_next;
            //进行下一组k个节点的反转，初始化
            pre = tail;
            head = tail->next;

        }
        return dummyNode->next;
    }
};