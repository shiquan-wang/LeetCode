#include<iostream>
#include<TreeNode.h>

using namespace std;

class Solution{
private:
    int res = 0;
    int travel(TreeNode* cur){
        if(cur == nullptr) return 2;

        int left = travel(cur->left);
        int right = travel(cur->right);
        // 情况1
        // 左右节点都有覆盖
        if(left == 2 && right == 2) return 0;

        // 情况2
        // left == 0 && right == 0 左右节点无覆盖
        // left == 1 && right == 0 左节点有摄像头，右节点无覆盖
        // left == 0 && right == 1 左节点有无覆盖，右节点摄像头
        // left == 0 && right == 2 左节点无覆盖，右节点覆盖
        // left == 2 && right == 0 左节点覆盖，右节点无覆盖
        if(left == 0 || right == 0){
            res++; return 1;
        }

        // 情况3
        // left == 1 && right == 2 左节点有摄像头，右节点有覆盖
        // left == 2 && right == 1 左节点有覆盖，右节点有摄像头
        // left == 1 && right == 1 左右节点都有摄像头
        // 其他情况前段代码均已覆盖
        if(left == 1 || right == 1) return 2;

        // 以上代码我没有使用else，主要是为了把各个分支条件展现出来，这样代码有助于读者理解
        // 这个 return -1 逻辑不会走到这里。
        return -1;
    }
public:
    int minCameraCover(TreeNode* root){
        res = 0;
        if(travel(root) == 0){
            res++;
        }
        return res;
    }
};