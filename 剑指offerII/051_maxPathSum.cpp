#include<iostream>
#include"TreeNode.h"
#include<algorithm>
using namespace std;
/* 
路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
路径和 是路径中各节点值的总和。
给定一个二叉树的根节点 root ，返回其 最大路径和，即所有路径上节点值之和的最大值。

解法：递归，后序遍历

* 对于一个父节点，它关心自己走入一个子树，从中捞取的最大收益，不关心具体怎么走。

* 定义dfs函数：返回当前子树能向父节点“提供”的最大路径和。即，一条从父节点延伸下来的路径，能在当前子树中捞取的最大收益。分三种情况：

    路径停在当前子树的根节点，在当前子树的最大收益：root.val
    走入左子树，在当前子树的最大收益：root.val + dfs(root.left)
    走入右子树，在当前子树的最大收益：root.val + dfs(root.right)
* 这对应了前面所说的三种选择，最大收益取三者最大：root.val+max(0, dfs(root.left), dfs(root.right))

再次提醒: 一条从父节点延伸下来的路径，不能走入左子树又掉头走右子树，不能两头收益。

当遍历到null节点时，null 子树提供不了收益，返回 0。

如果某个子树 dfs 结果为负，走入它，收益不增反减，该子树就没用，需杜绝走入，像对待 null 一样让它返回 0（壮士断腕）。
 */
class Solution{
public:
    int res = INT_MIN;
    int dfs(TreeNode* root){
        if(root == nullptr) return 0;//递归的终止条件
        
        //递归计算左右节点的最大收益
        int left_sum = max(0, dfs(root->left));//左右子树收益如果小于0，则舍去
        int right_sum = max(0, dfs(root->right));
        int priceNewpath = root->val + left_sum + right_sum;//计算经过当前节点的最大路径和，经过当前节点的最大路径和取决去当前节点的值和左右子节点的最大贡献值
        res = max(res, priceNewpath);

        return root->val + max(left_sum, right_sum);//返回到上一层的最大贡献值，取决于当前节点值和左右子节点中一个的最大贡献值
    }
    int maxPathSum(TreeNode* root){
        dfs(root);
        return res;
    }
};