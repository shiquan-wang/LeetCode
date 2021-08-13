#include<iostream>
#include<TreeNode.h>
#include<math.h>
using namespace std;

class Solution{
public:
//完全二叉树只有两种情况，情况一：就是满二叉树，情况二：最后一层叶子节点没有满。
//对于情况一，可以直接用 2^树深度 - 1 来计算，注意这里根节点深度为1。
//对于情况二，分别递归左孩子，和右孩子，递归到某一深度一定会有左孩子或者右孩子为满二叉树，然后依然可以按照情况1来计算。

    int countNodes(TreeNode* root){
        if(root == nullptr) return 0;
        
        TreeNode *left = root->left;
        TreeNode *right = root->right;

        int leftHeight = 0, rightHeight = 0;
        while(left){
            left = left->left;
            leftHeight++;
        }

        while(right){
            right = right->right;
            rightHeight++;
        }

        if(leftHeight == rightHeight){
            //return (2<<leftHeight) - 1;
            return pow(2, leftHeight+1) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};