#include<iostream>
#include"TreeNode.h"

using namespace std;

class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == q || root == p || root == nullptr) return root;//如果遇到p,q或空节点，返回 说明p q存在于root的左右子树或者不在root的左右子树中

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        //如果left和right都不为空，root就是最近公共节点
        //如果left为空，right不为空，就返回right，说明目标节点是通过right返回的，反之依然
        //如果left right都为空，则说明p q 不在root的子树中，返回空
        if(left != nullptr && right != nullptr) return root;
        else if(left == nullptr && right != nullptr) return right;
        else if(left != nullptr && right == nullptr) return left;
        else return nullptr;//left == right == nullptr

    }
};