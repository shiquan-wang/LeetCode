#include<iostream>
#include"TreeNode.h"

using namespace std;

class Solution{
public:
   /*  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr) return nullptr;//

        if(root->val > p->val && root->val > q->val){//左
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            if(left) return left;
        }else if(root->val < p->val && root->val < q->val){//右
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
            if(right) return right;
        }else {
            return root;//公共祖先节点，
        }
    } */

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){

        if(root->val > p->val && root->val > q->val){//左
            return lowestCommonAncestor(root->left, p, q);  
        }else if(root->val < p->val && root->val < q->val){//右
            return lowestCommonAncestor(root->right, p, q);
        }else {
            return root;//公共祖先节点，
        }
    }
};