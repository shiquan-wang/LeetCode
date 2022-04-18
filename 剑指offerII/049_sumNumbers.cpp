#include<iostream>
#include"TreeNode.h"
#include<vector>

using namespace std;
/* 
给定一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。

每条从根节点到叶节点的路径都代表一个数字：

例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
计算从根节点到叶节点生成的 所有数字之和 。

 */
class Solution{
public:
    int dfs(TreeNode* root, int prevSum){
        if(root == nullptr) return 0;//递归的终止条件
        int sum = prevSum*10 + root->val;
        if(root->left == nullptr && root->right == nullptr){
            return sum;
        }else{
            return dfs(root->left, sum) + dfs(root->right, sum);
        }
    }
    int sumNumbers(TreeNode* root){
        return dfs(root, 0);
    }
};