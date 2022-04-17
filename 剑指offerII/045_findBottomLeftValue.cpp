#include<iostream>
#include<queue>
#include"TreeNode.h"

using namespace std;

class Solution{
public:
    int findBottomLeftValue(TreeNode* root){
        TreeNode* temp = root;
        queue<TreeNode*> que;
        que.push(temp);
        int res;
        while (!que.empty())
        {
            int n = que.size();//记录每层节点数
            res = que.front()->val;//当前层最左边节点的value
            for(int i = 0; i < n; ++i){//遍历当前层节点，将下一层节点入队
                temp = que.front();
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
                que.pop();
            }
        }
        return res;
    }
};