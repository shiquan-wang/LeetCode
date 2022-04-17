#include<iostream>
#include<queue>
#include<vector>
#include"TreeNode.h"

using namespace std;
/* 
给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 */

class Solutio{
public:
    vector<int> righeSideView(TreeNode* root){
        if(root == nullptr) return {};
        vector<int> res;
        queue<TreeNode*> que;
        TreeNode* temp = root;
        que.push(temp);

        while (!que.empty())
        {
            int n = que.size();
            for(int i = 0; i < n; ++i){
                temp = que.front();
                if(i == n-1) res.push_back(temp->val);//将最右边的节点放在res中
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
                que.pop();
            }
        }
        return res;    
    }
};