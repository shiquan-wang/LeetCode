#include<iostream>
#include"TreeNode.h"

using namespace std;

class Solution{
private:
    TreeNode* pre = nullptr;
public:
    bool isValidBST(TreeNode* root){
        
        if(root == nullptr) return true;

        bool left_bst = isValidBST(root->left);

        if(pre != nullptr && pre->val >= root->val) return false;
        pre = root;

        bool right_bst = isValidBST(root->right);

        return left_bst&&right_bst;
    }
    /* bool isValidBST(TreeNode* root){
        if(root == nullptr) return true;

        if(root->left){
            if(root->left->val >= root->val){
                return false;
            }
        }

        if(root->right){
            if(root->right->val <= root->val){
                return false;
            }
        }

        return isValidBST(root->left)&&isValidBST(root->right);
    } */
};