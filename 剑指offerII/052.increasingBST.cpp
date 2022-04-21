#include<iostream>
#include"TreeNode.h"
#include<queue>
using namespace std;


/* 
给你一棵二叉搜索树的 root ，请你 按中序遍历 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。
思路一：
dfs遍历存储节点，然后再构建二叉树
思路二：
在中序遍历的时候，修改节点指向就可以实现。具体地，当我们遍历到一个节点时，把它的左孩子设为空，并将其本身作为上一个遍历到的节点的右孩子。
这里需要有一些想象能力。递归遍历的过程中，由于递归函数的调用栈保存了节点的引用，因此上述操作可以实现

 */
class Solution{
public:
    queue<int> que;
    void dfs(TreeNode* root){//中序遍历二叉搜索树，将节点val存储在队列中
        if(root == nullptr) return;//递归的返回条件

        dfs(root->left);
        que.push(root->val);
        dfs(root->right);
    }
    TreeNode* increasingBST(TreeNode* root){
        dfs(root);//递归遍历，将节点存储在队列中
        TreeNode* res = new TreeNode();
        TreeNode* temp = res;
        while (!que.empty())
        {
            TreeNode* node = new TreeNode(que.front());
            que.pop();
            temp->right = node;
            temp = temp->right;
        }
        return res->right;
    }
};