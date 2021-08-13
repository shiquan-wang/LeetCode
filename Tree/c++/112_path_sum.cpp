#include<iostream>
#include<TreeNode.h>

using namespace std;

class Solution{
public:
    bool hasPathSum(TreeNode* root, int targetSum){
        if(!root){
            return false;
        }
        if(!root->left && !root->right && targetSum == root->val){
            return true;
        }
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
        //dps 每遍历一个节点减去该节点的val,当到叶子节点时如果sum为0则该路径存在
    }
}