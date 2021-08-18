#include<iostream>
#include"TreeNode.h"
#include<vector>
#include<stack>

using namespace std;

class Solution{
public:
    /* vector<int> preorderTraversal(TreeNode* root){
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = nullptr;
        if(root == nullptr) return res;
        st.push(root);

        while (!st.empty())
        {
            cur = st.top();
            st.pop();
            res.push_back(cur->val);

            if(cur->right) st.push(cur->right);//迭代过程中需要先进栈右节点，这样才能使得出栈时先处理左节点(即先将左节点放入res数组中。
            if(cur->left) st.push(cur->left);
        }//res中左右

        return res;
    }
 */
    /* vector<int> postorderTraversal(TreeNode* root){
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = nullptr;
        if(root == nullptr) return res;
        st.push(root);

        while (!st.empty())
        {
            cur = st.top();
            st.pop();
            res.push_back(cur->val);
            if(cur->left) st.push(cur->left);
            if(cur->right) st.push(cur->right);//中右左
        }
        reverse(res.begin(), res.end());//反转后 中左右

        return res;
    }
 */
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> res;
        if(root == nullptr) return res;
        stack<TreeNode*> st;
        TreeNode* cur = root;

        while(cur != nullptr || !st.empty()){
            while(cur != nullptr){
                res.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            cur = cur->right;
        }
        return res;
    }

    vector<int> postorderTraversal(TreeNode* root){
        vector<int> res;
        if(root == nullptr) return res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;//记录上一个处理过的节点

        while(cur != nullptr || !st.empty()){
            while(cur != nullptr){//找到最左边的叶子节点
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            if(cur->right == nullptr || cur->right == pre){//右孩子节点不存在或者右孩子节点已经处理过。
                res.push_back(cur->val);
                pre = cur;
                cur = nullptr;
            }else{//右孩子节点存在
                st.push(cur->right);
                cur = cur->right;
            }
        }
        return res;
    }

    vector<int> inorderTraversal(TreeNode* root){
        vector<int> res;
        if(root == nullptr) return res;
        stack<TreeNode*> st;
        TreeNode* cur = root;

        while(cur != nullptr || !st.empty()){
            while(cur != nullptr){
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            res.push_back(cur->val);
            cur = cur->right;

        }
        return res;
    }


};