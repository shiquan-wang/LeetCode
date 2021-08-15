#include<iostream>
#include"TreeNode.h"//自己写的头文件要用双括号或者更改项目的头文件目录
#include<vector>

using namespace std;

class Solution{
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        if(postorder.size() == 0) return nullptr;//第一步：如果postorder长度为0则代表该处是空节点

        int inorder_size = inorder.size(), postorder_size = postorder.size();

        int root_value = postorder[postorder_size-1];
        TreeNode* root = new TreeNode(root_value);//第二步：找到后序遍历序列的最后一个元素即为树的根节点
        if(postorder.size() == 1) return root;

        int index = -1;
        for(int i=0; i<inorder_size; ++i){//第三步：在中序序列中找到root节点，将其分割为左右子树两部分
            if(inorder[i] == root_value){
                index = i;
                break;
            }
        }

        //第四步：切割中序序列
        vector<int>left_inorder(inorder.begin(), inorder.begin()+index);
        vector<int>right_inorder(inorder.begin()+index+1, inorder.end());

        //第五步：切割后序序列
        vector<int>left_postorder(postorder.begin(), postorder.begin()+index);
        vector<int>right_postorder(postorder.begin()+index, postorder.end()-1);
      //log
      /*   cout<<"---";
        for(int i : left_inorder){
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<"---";
        for(int i : right_inorder){
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<"---";
        for(int i : left_postorder){
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<"---";
        for(int i : right_postorder){
            cout<<i<<" ";
        }
        cout<<endl; */

        //第六步：构造左右子树
        root->left = buildTree(left_inorder, left_postorder);
        root->right = buildTree(right_inorder, right_postorder);

        return root;
    }
};

int main(){
    vector<int> inorder = {9,3,15,20,7};
    vector<int> posterorder = {9,15,7,20,3};
    Solution s;
    TreeNode* root = s.buildTree(inorder, posterorder);
}