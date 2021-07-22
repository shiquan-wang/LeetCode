#include<iostream>
#include<TreeNode.h>

using namespace std;

class Solution{
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2){
        if(root1 == nullptr || root2 == nullptr){
            return root1 == nullptr ? root2 : root1;
        }
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};