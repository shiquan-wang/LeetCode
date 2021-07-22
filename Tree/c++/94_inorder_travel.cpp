#include<iostream>
#include<TreeNode.h>
#include<vector>
#include<stack>
using namespace std;

class Solution{
public:
    void inorder(TreeNode* root, vector<int>& v){
        if(root == nullptr){
            return;
        }
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> v ;
        inorder(root, v);
        return v;
    }

    vector<int> inorderTraversal2(TreeNode* root){
        vector<int>res;
        stack<TreeNode*> temp;
        while(root!=nullptr || !temp.empty()){
            while(root!=nullptr){
                temp.push(root);
                root = root->left;
            }

            root = temp.top();
            temp.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};