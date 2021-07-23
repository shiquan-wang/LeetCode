#include<iostream>
#include<TreeNode.h>
#include<algorithm>

using namespace std;

class Solution{
public:
    /* int minDepth(TreeNode* root){
        if(root == nullptr) return 0;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    } */

    //最小深度与最大深度的区别在于最小深度是到叶子节点的长度
    //如果左子树为空，右子树不为空，说明最小深度是 1 + 右子树的深度。
    //反之，右子树为空，左子树不为空，最小深度是 1 + 左子树的深度。 
    //最后如果左右子树都不为空，返回左右子树深度最小值 + 1 。
//采用后序遍历，这样可以节省运算时间，避免重复计算部分中间节点
    int minDepth(TreeNode* root){
        if(root == nullptr) return 0;

        int left_depth = minDepth(root->left);
        int right_depth = minDepth(root->right);

        if(root->left == nullptr && root->right != nullptr){
            return right_depth + 1;
        }
        if(root->left != nullptr && root->right == nullptr){
            return left_depth + 1;
        }

        return min(left_depth, right_depth) + 1;
    }
};