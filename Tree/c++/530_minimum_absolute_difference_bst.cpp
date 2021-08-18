#include<iostream>
#include"TreeNode.h"
#include<algorithm>
#include<stack>
using namespace std;

class Solution{
private:
    int res = INT_MAX;
    TreeNode* pre = nullptr;
    void traversal(TreeNode* cur){
        if(cur == nullptr) return;

        traversal(cur->left);

        if(pre != nullptr){
            res = min(res, cur->val - pre->val);
        }
        pre = cur;

        traversal(cur->right);
    }
public:
    int getMinimumDifference(TreeNode* root){
        traversal(root);
        return res;
    }
    int getMinimumDifference2(TreeNode* root){
        stack<TreeNode*> st;
        TreeNode* pre = nullptr;
        int res = INT_MAX;
        if(root!=nullptr) st.push(root);
        TreeNode* cur = root;

        while(!st.empty()){
            while(cur->left){
                st.push(cur->left);
                cur = cur->left;
            }

            if(pre != nullptr && pre->val < cur->val){
                res = min(res, cur->val - pre->val);
            }
            pre = cur;
            

        }
    }
};