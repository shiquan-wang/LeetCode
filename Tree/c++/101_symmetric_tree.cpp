#include<iostream>
#include<TreeNode.h>

using namespace std;

class Solution{
public:
//同步移动p和q,p向左 && q向右 p向左 
// 
    bool check(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root){
        return check(root, root);
    }

    
};