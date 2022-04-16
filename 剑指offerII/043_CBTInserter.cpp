#include<iostream>
#include"TreeNode.h"
#include<queue>
using namespace std;

/* 
设计一个用完全二叉树初始化的数据结构 CBTInserter，它支持以下几种操作：

CBTInserter(TreeNode root) 使用根节点为 root 的给定树初始化该数据结构；
CBTInserter.insert(int v)  向树中插入一个新节点，节点类型为 TreeNode，值为 v 。使树保持完全二叉树的状态，并返回插入的新节点的父节点的值；
CBTInserter.get_root() 将返回树的根节点。

思路：
1. 类中定义一个队列用于维护层序遍历
2. 在初始化过程通过层序遍历找到第一个不同时拥有左树右树的结点，返回。
3. 在插入过程中，判断是插入左树还是右树，若是右树，则将队首踢出。并将新加入的节点入队。
(层次遍历不同的是，需要再遍历过程中找到第一个可以插入左子树或者右子树的节点，并在这里返回该节点用于后续的插入操作)
*/
class CBTInserter{
public:
    TreeNode* head = nullptr;
    queue<TreeNode*> que;
    CBTInserter(TreeNode* node){
        head = node;
        que.push(head);
        while (!que.empty())
        {
            int n = que.size();
            for(int i = 0; i < n; ++i){
                auto temp = que.front();//TreeNode* temp = que.front();
                if(temp->left) que.push(temp->left);//左子树存在则插入左子树
                if(temp->left == nullptr ) return;//左子树不存在则该节点temp可以插入左子树
                if(temp->right) que.push(temp->right);//temp右子树也存在，直接入队
                if(temp->right == nullptr) return;//右子树不存在，temp可以插入右子树节点，
                que.pop();//temp左右子树都存在，则temp不可以插入新的节点，直接出队
            }
        }
    }

    int insert(int v){
        auto temp = que.front();
        if(temp->left){//左子树存在，则右子树可以插入
            temp->right = new TreeNode(v);
            que.push(temp->right);
            que.pop();//temp左右子树都有了，不能继续插入节点，直接出队
        }else{
            temp->left = new TreeNode(v);
            que.push(temp->left);
        }
        return temp->val;
    }

    TreeNode* get_root(){
        return head;
    }
};