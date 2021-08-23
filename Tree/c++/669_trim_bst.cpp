#include<iostream>
#include"TreeNode.h"

using namespace std;

class Solution{
public:
    TreeNode* trimBST(TreeNode* root, int low, int high){
        if(root == nullptr) return root;//termination condition

        if(root->val < low) return trimBST(root->right, low, high);//如果root（当前节点）的元素小于low的数值，那么应该递归右子树，并返回右子树符合条件的头结点
        if(root->val > high) return trimBST(root->left, low, high);//如果root(当前节点)的元素大于high的，那么应该递归左子树，并返回左子树符合条件的头结点

        root->left = trimBST(root->left, low, high);//root 满足[low high]将下一层处理完左子树的结果赋给root->left，处理完右子树的结果赋给root->right
        root->right = trimBST(root->right, low, high);

        return root;
    }
};