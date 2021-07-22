#include<iostream>
#include<TreeNode.h>
#include<vector>
#include<queue>

using namespace std;

class Solution{
public:
    //层次遍历
    vector<vector<int>> levelOrder(TreeNode* root){
        queue<TreeNode*> q;
        vector<vector<int>> v;
        TreeNode *p = root;
        
        if(p != nullptr) q.push(p);

        while(!q.empty()){
            int leversize = q.size();
            vector<int> temp;//临时数组用于存储每一层的节点val
            for(int i = 0; i < leversize; ++i){
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                temp.push_back(q.front()->val);
                q.pop();
            }
            v.push_back(temp);//将本层的节点放入整棵树的vector中
        }
        return v;
    }
};