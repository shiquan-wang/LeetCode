#include<iostream>
#include"ListNode.h"
#include<vector>
using namespace std;

class Solution{
public:
    bool isPalindrome(ListNode* head){//O(N) O(N)时间和空间复杂度
        ListNode *node = head;
        vector<int> vec;

        while (node != nullptr)
        {
            vec.emplace_back(node->val);//c++ 11新增emplace_back 速度比push_back要快，因为它省略了移动构造函数和拷贝构造函数的过程，右值引用只调用构造函数
            node = node->next;
        }

        int i = 0, j = vec.size() - 1;
        while (i < j)
        {
            if(vec[i] != vec[j]){
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
    //如果想降低空间复杂度，可以反转后半部分链表，然后再比较。
    //具体1：快慢指针找到链表中点，2：反转后半部分链表 3：比较 4：恢复链表 5：结束
};

int main(){
    vector<int> value = {1, 2, 3, 3, 2, 1};
    ListNode *head = new ListNode();

    for(int i = value.size() - 1; i >= 0; --i){
        ListNode *temp = new ListNode(value[i]);
        temp->next = head->next;
        head->next = temp;
    }

    Solution s1;
    cout<<s1.isPalindrome(head->next);
}