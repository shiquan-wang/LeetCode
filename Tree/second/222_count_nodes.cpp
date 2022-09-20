#include<iostream>
#include"TreeNode.h"

using namespace std;
/* 
给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，
并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2^h 个节点。

完全二叉树只有两种情况，情况一：就是满二叉树，情况二：最后一层叶子节点没有满。

对于情况一，可以直接用 2^树深度 - 1 来计算，注意这里根节点深度为1。

对于情况二，分别递归左孩子，和右孩子，递归到某一深度一定会有左孩子或者右孩子为满二叉树，然后依然可以按照情况1来计算。
 */
class Solution{
public:
    int countNodes(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        TreeNode* left_node = root->left;
        TreeNode* right_node = root->right;
        int left_height = 0, right_height = 0;
        while (left_node)
        {
            left_height++;
            left_node = left_node->left;
        }
        while (right_node)
        {
            right_height++;
            right_node = right_node->right;
        }
        
        if(left_height == right_height){
            return (2<<left_height) - 1;
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);
        
    }
};