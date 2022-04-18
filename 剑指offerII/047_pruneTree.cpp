#include<iostream>
#include"TreeNode.h"
#include<queue>

using namespace std;
/* 
给定一个二叉树 根节点 root ，树的每个节点的值要么是 0，要么是 1。请剪除该二叉树中所有节点的值为 0 的子树。

节点 node 的子树为 node 本身，以及所有 node 的后代。
思路1：没有考虑子树的问题，只考虑的每个节点的问题，错误
思路2: 递归的方法来判断一个子树是否质保含0

 */
class Solution{
public:
    TreeNode* pruneTree1(TreeNode* root){
        if(root->val == 0) return nullptr;
        queue<TreeNode*> que;
        TreeNode* temp = root;
        que.push(temp);

        while (!que.empty())
        {
            int n = que.size();//每一层的节点数
            for(int i = 0; i < n; ++i){//遍历该层的所有节点
                temp = que.front();
                que.pop();
                //左子树存在且左子树val != 0 左子树入队，否则左子树为nullptr
                /* if(temp->left){
                    if(temp->left->val == 0){
                        temp->left = nullptr;
                    }else{
                        que.push(temp->left);
                    }
                } */
                //优化后写法
                if(temp->left && temp->left->val == 1){
                    que.push(temp->left);
                }else{
                    temp->left == nullptr;
                }

                if(temp->right && temp->right->val == 1){
                    que.push(temp->right);
                }else{
                    temp->right == nullptr;
                }
            }
        }
        
    }
    TreeNode* pruneTree(TreeNode* root){
        return dfs(root);
    }
    TreeNode* dfs(TreeNode* node){
        if(node->left == nullptr && node->right == nullptr){//递归的终止条件
            if(node->val == 0){
                return nullptr;
            }else{
                return node;
            }
        }

        if(node->left){
            node->left = dfs(node->left);
        }

        if(node->right){
            node->right = dfs(node->right);
        }
        if(node->val == 0 && node->left == nullptr && node->right == nullptr){
            return nullptr;
        }
        return node;
    }

    TreeNode* pruneTree2(TreeNode* root){
        //先判断孩子节点再判断父亲节点，因此使用后序遍历即可完成
        if(root == nullptr) return nullptr;

        root->left = pruneTree2(root->left);
        root->right = pruneTree2(root->right);

        if(root->left == nullptr && root->right == nullptr && root->val == 0) return nullptr;
        return root;
    }
};