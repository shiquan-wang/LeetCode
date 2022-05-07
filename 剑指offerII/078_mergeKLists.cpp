#include<iostream>
#include<vector>
#include"ListNode.h"

using namespace std;

class Solution{
private:
    ListNode* merge_two_list(ListNode* root1, ListNode* root2){//合并两个有序链表
        ListNode *node1 = root1, *node2 = root2;
        ListNode* root = new ListNode();
        ListNode* temp = root;
        while (node1 != nullptr && node2 != nullptr)
        {
            if(node1->val < node2->val){
                // temp->next = new ListNode(node1->val);
                
                // node1 = node1->next;

                //直接修改指针，节省存储空间
                temp->next = node1;
                node1 = node1->next;
            }else{
                // temp->next = new ListNode(node2->val);
                
                // node2 = node2->next;
                temp->next = node2;
                node2 = node2->next;
            }
            temp = temp->next;
        }

        /* 
        简单写法如下：temp->next = node1 ? node1 : node2;
        while (node1 != nullptr)
        {
            // temp->next = new ListNode(node1->val);
            // node1 = node1->next;
            // temp = temp->next;
            //直接修改指针，节省空间
            temp->next = node1;
            // node1 = node1->next;
            // temp = temp->next;
        }

        while (node2 != nullptr)
        {
            // temp->next = new ListNode(node2->val);
            // node2 = node2->next;
            // temp = temp->next;
            //直接修改指针，节省空间
            temp->next = node2;
            // node2 = node2->next;
            // temp = temp->next;
        }
        */
        temp->next = node1 ? node1 : node2;
        return root->next;
    }
public:
    ListNode* mergeKLists_two_merge(vector<ListNode*>& lists){//两两有序链表合并
        if(lists.size() == 0) return nullptr;
        ListNode* root = lists[0];

        for(int i = 1; i < lists.size(); ++i){
            root = merge_two_list(root, lists[i]);
        }

        return root;
    }
    ListNode* merge(vector<ListNode*>& lists, int left, int right){
        if(left == right) return lists[left];
        if(left > right) return nullptr;
        int mid = (right - left) / 2 + left;
        return merge_two_list(merge(lists, left, mid), merge(lists, mid+1, right));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists){
        return merge(lists, 0, lists.size() - 1);
    }
};