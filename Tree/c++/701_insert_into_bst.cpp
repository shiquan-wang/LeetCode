#include<iostream>
#include"TreeNode.h"

using namespace std;

class Solution{
public:
    
    TreeNode* insertIntoBST(TreeNode* root, int val){
        if(root == nullptr){
            root = new TreeNode(val);
            return root;
        } 

        if(root->val < val){
            root->right = insertIntoBST(root->right, val);
        }else{
            root->left = insertIntoBST(root->left, val);
        }

        return root;
    }
};