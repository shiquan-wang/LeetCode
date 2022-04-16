#include<iostream>
#include"TreeNode.h"
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    vector<int> largestValues(TreeNode* root){
        if(root == nullptr) return {};
        TreeNode* temp = root;
        queue<TreeNode*> que;
        vector<int> res;
        que.push(temp);
        while (!que.empty())
        {
            int n = que.size();//记录每一层的节点个数
            int value = INT32_MIN;
            for(int i = 0; i < n; ++i){
                temp = que.front();
                value = max(value, temp->val);
                if(temp->left){
                    que.push(temp->left);
                }
                if(temp->right){
                    que.push(temp->right);
                }
                que.pop();
            }
            res.push_back(value);
        }
        
        return res;
    }
};