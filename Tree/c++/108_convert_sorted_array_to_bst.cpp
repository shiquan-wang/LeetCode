#include<iostream>
#include"TreeNode.h"
#include<vector>

using namespace std;

class Solution{
private:
    TreeNode* buildNode(vector<int>& nums, int left, int right){
        if(left > right) return nullptr;

        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildNode(nums, left, mid-1);
        root->right = buildNode(nums, mid + 1, right);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums){
        int len = nums.size();
        TreeNode* root = buildNode(nums, 0, len-1);
        return root;
    }
};

int main(){
    vector<int> v = {-10, -3, 0, 5, 9};
    Solution s;
    TreeNode* root = s.sortedArrayToBST(v);
}