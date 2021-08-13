#include<iostream>
#include<TreeNode.h>
#include<vector>
#include<string>
using namespace std;

class Solution{
public:
    void dps(TreeNode* cur, vector<int>& path, vector<string>& res){
        path.push_back(cur->val);
        if(cur->left == nullptr && cur->right == nullptr){
            string spath;
            for(int i = 0; i < path.size() - 1; ++i){
                spath += to_string(path[i]);
                spath += "->";
            }
            spath += to_string(path[path.size() - 1]);
            res.push_back(spath);
            return;
        }

        if(cur->left){
            dps(cur->left, path, res);
            path.pop_back();
        }

        if(cur->right){
            dps(cur->right, path, res);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root){
        vector<string> res;
        vector<int> path;
        if(root == nullptr) return res;
        dps(root, path, res);
        return res;
    }
};