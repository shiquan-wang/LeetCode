#include<iostream>
#include"TreeNode.h"
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, vector<int>> index;
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param preOrder int整型vector 
     * @param inOrder int整型vector 
     * @return TreeNode类vector
     */
    TreeNode* buildTree(vector<int>& preOrder, vector<int>& inOrder, int pre_left, int pre_right, int in_left, int in_right){
        if(pre_left > pre_right){
            return nullptr;
        }
        int pre_root = pre_left;
        vector<int> in_root = index[preOrder[pre_root]];
        TreeNode* root = new TreeNode(preOrder[pre_root]);
        for(int i = 0; i < in_root.size(); ++i){
            
            int in_root_in = in_root[i];
            int left_size = in_root_in - in_left;
            root->left = buildTree(preOrder, inOrder, pre_left+1, pre_left+left_size, in_left,in_root_in-1);
            root->right =  buildTree(preOrder, inOrder, pre_left+left_size+1, pre_right, in_root_in + 1, in_right);
            return root;
        }
        return root;
    }
    vector<TreeNode*> getBinaryTrees(vector<int>& preOrder, vector<int>& inOrder) {
        // write code here
        int n = preOrder.size();
        for(int i = 0; i < n; ++i){
            index[inOrder[i]].push_back(i);
        }
        vector<TreeNode*> ans;
        
        vector<int> in_root = index[preOrder[0]];
        for(int i = 0; i < in_root.size(); ++i){
            TreeNode* root = new TreeNode(preOrder[0]);
            int in_root_in = in_root[i];
            int left_size = in_root_in - 0;
            root->left = buildTree(preOrder, inOrder, 1, 0 + left_size, 0,in_root_in-1);
            root->right =  buildTree(preOrder, inOrder, 0+left_size+1, n-1, in_root_in + 1, n-1);
            ans.push_back(root);
        }
        return ans;
    }
};

int main(){
    vector<int> preOrder = {1, 1, 2};
    vector<int> inOrder = {1, 2, 1};
    Solution s1;
    vector<TreeNode*> ans = s1.getBinaryTrees(preOrder, inOrder);
}