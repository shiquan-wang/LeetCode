#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0), left(nullptr), right(nullptr){}
    TreeNode(int val):val(val), left(nullptr), right(nullptr){}
    TreeNode(int val, TreeNode *left, TreeNode *right):val(val), left(left), right(right){}
};

class Solution{
public:
    int depth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }else{
            return max(depth(root->left), depth(root->right)) + 1;
        }
    }
    //AVL 定义是每个节点的左右字数高度差不超过1，
    bool isBalanced(TreeNode* root){
        if(root == nullptr){
            return true;
        }else{
            return abs(depth(root->left) - depth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        }
        // if(abs(depth(root->left) - depth(root->right)) != 1){
        //     return false;
        // }else{
        //     if(root->left){
        //         isBalanced(root->left);
        //     }
        //     if(root->right){
        //         isBalanced(root->right);
        //     }
        //     return true;
        // }
    }
};