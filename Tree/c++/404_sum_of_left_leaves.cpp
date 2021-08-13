#include<iostream>
#include<TreeNode.h>

using namespace std;

class Solution{
public:
    int sumOfLeftLeaves(TreeNode* root){
        if(root == nullptr) return 0;

        int left = sumOfLeftLeaves(root->left);
        int right = sumOfLeftLeaves(root->right);

        int mid = 0;
        if(root->left && root->left->left == nullptr && root->left->right == nullptr){//如果左孩子存在判断左孩子是否是左叶子节点
            mid = root->left->val;
        }
        int sum = left + right + mid;
        return sum;
    }
};