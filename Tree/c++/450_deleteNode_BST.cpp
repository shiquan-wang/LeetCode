#include<iostream>
#include"TreeNode.h"

using namespace std;

class Solution{
public:
    TreeNode* deleteNode(TreeNode* root, int key){
        if(root == nullptr) return root;//key不存在

        if(root->val == key){
            if(root->left == nullptr && root->right == nullptr){//key是叶子节点
                return nullptr;
            }
            else if(root->left == nullptr) return root->right;//key左子树为空，右子树不为空
            else if(root->right == nullptr) return root->left;//key右子树为空，左子树不为空
            else {//左右孩子不为空，将删除节点的左子树放在删除节点右子树的最左边节点的左孩子。
                TreeNode* cur = root->right;
                while(cur->left != nullptr){
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* tmp = root;
                root = root->right;
                delete tmp;
                return root;
            }
        }

        if(root->val > key) root->left =  deleteNode(root->left, key);
        if(root->val < key) root->right =  deleteNode(root->right, key);

        return root;
    }
};