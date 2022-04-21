#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0), left(nullptr), right(nullptr){}
    TreeNode(int val):val(val), left(nullptr), right(nullptr){}
    TreeNode(int val, TreeNode* left, TreeNode* right):val(val), left(left), right(right){}
};
/* 
实现一个二叉搜索树迭代器类BSTIterator ，表示一个按中序遍历二叉搜索树（BST）的迭代器：

BSTIterator(TreeNode root) 初始化 BSTIterator 类的一个对象。BST 的根节点 root 会作为构造函数的一部分给出。指针应初始化为一个不存在于 BST 中的数字，且该数字小于 BST 中的任何元素。
boolean hasNext() 如果向指针右侧遍历存在数字，则返回 true ；否则返回 false 。
int next()将指针向右移动，然后返回指针处的数字。
注意，指针初始化为一个不存在于 BST 中的数字，所以对 next() 的首次调用将返回 BST 中的最小元素。

可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST 的中序遍历中至少存在一个下一个数字。

 */
class BSTIterator{
private:
    vector<int> vec;//数组来存放二叉搜索树的中序遍历结果
    int count;
public:
    void dfs(TreeNode* root){
        if(root == nullptr) return;
        dfs(root->left);
        vec.push_back(root->val);
        dfs(root->right);
        return;
    }
    BSTIterator(TreeNode* root){//中序遍历二叉搜索树
        dfs(root);
        count = 0;//记录next调用时取出的元素下标
    }

    int next(){
        return vec[count++];
    }

    bool hasNext(){
        if(count < vec.size()){
            return true;
        }
        return false;
    }
};
