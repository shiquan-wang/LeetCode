#include<iostream>
#include"TreeNode.h"

using namespace std;
/* 
给定一棵二叉搜索树和其中的一个节点 p ，找到该节点在树中的中序后继。如果节点没有中序后继，请返回 null 。
节点 p 的后继是值比 p.val 大的节点中键值最小的节点，即按中序遍历的顺序节点 p 的下一个节点。

 */
class Solution{
public:
    TreeNode* ans;
    bool flag;
    void dfs(TreeNode* root, TreeNode* p){
        if(root == nullptr) return;

        dfs(root->left, p);
        if(flag == true && ans == nullptr){//flag == true代表已经找到节点p,ans==nullptr代表还没有找到p的中序后继节点
            ans = root;
            return;
        }
        if(root->val == p->val){//找到节点p,则将flag置为true
            flag = true;
        }
        dfs(root->right, p);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
        ans = nullptr;
        flag = false;
        dfs(root, p);
        return ans;
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
        
    }
};