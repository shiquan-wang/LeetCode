#include<iostream>
#include<vector>
#include<TreeNode.h>
#include<algorithm>
using namespace std;

class Solution{
private:
    vector<int> robTree(TreeNode* cur){
        if(cur == nullptr) return vector<int>{0, 0};

        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        //偷cur
        int val1 = cur->val + left[0] + right[0];

        //不偷cur
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);

        return {val2, val1};
    }
public:
    int rob(TreeNode* root){
        vector<int> res = robTree(root);
        return max(res[0], res[1]);
    }
};