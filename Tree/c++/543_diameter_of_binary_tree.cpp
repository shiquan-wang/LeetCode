#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0), left(nullptr), right(nullptr){}
    TreeNode(int val):val(val), left(nullptr), right(nullptr){}
    TreeNode(int val, TreeNode *left, TreeNode *right):val(0), left(left), right(right){}
};

class Solution{
private:
    int diameter = 0;
    int depth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int l = depth(root->left);
        int r = depth(root->right);
        //更新直径，左右子树深度和 等于 经过当前根节点的最大直径
        diameter = max(diameter, l + r);
        //返回左右子树深度较大的值
        return max(l, r) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root){
        depth(root);
        return diameter;
    }
};