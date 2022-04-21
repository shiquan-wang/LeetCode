#include<iostream>
#include<vector>
#include"TreeNode.h"
#include<unordered_set>
using namespace std;

class Solution{
private:
    void inorder(TreeNode* root, int k){
        if(root == nullptr) return;
        if(flag == true) return;

        inorder(root->left, k);

        if(st.find(k - root->val) != st.end()){//寻找是否存在k - root->val 的节点
            flag = true;
            return;
        }
        st.insert(root->val);
        inorder(root->right, k);
        return;
    }
public:
    unordered_set<int> st;
    bool flag;
    bool findTarget(TreeNode* root, int k){
        flag = false;
        inorder(root, k);
        return flag;
    }
};