#include<iostream>
#include"TreeNode.h"
#include<vector>

using namespace std;

class Solution{
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums){
        int nums_size = nums.size();
        if(nums_size == 0) return nullptr;//终止条件
        
        int max_index = -1, max = -1;//寻找根节点val 建立root
        for(int i=0; i<nums_size; ++i){
            if(nums[i] > max){
                max_index = i;
                max = nums[i];
            }
        }
        TreeNode* root = new TreeNode(nums[max_index]);
        if(nums_size == 1) return root;//左右子树都为空提前返回节省时间

        vector<int> left(nums.begin(), nums.begin()+max_index);//切分左右子树序列
        vector<int> right(nums.begin()+max_index+1, nums.end());

        //log log
        for(int i : left){
            cout<<i<<" ";
        }
        cout<<endl;
        for(int i : right){
            cout<<i<<" ";
        }
        cout<<endl;

        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);

        return root;

    }
};

int main(){
    vector<int> nums = {3,2,1,6,0,5};
    Solution s;
    TreeNode* root = s.constructMaximumBinaryTree(nums);
}