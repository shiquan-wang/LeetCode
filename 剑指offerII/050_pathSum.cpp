#include<iostream>
#include"TreeNode.h"
#include<unordered_map>
using namespace std;
/*
给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。

 */
class Solution{
public:
    int rootSum(TreeNode* root, int targetSum){//表示以节点root向下目标为targetsum的路径数
        if(root == nullptr) return 0;
        int ret = 0;
        if(root ->val == targetSum){
            ret++;
        }
        ret += rootSum(root->left, targetSum - root->val);
        ret += rootSum(root->right, targetSum - root->val);
        return ret;
    }

    int pathSum1(TreeNode* root, int targetSum){//先序遍历遍历所有节点，寻找所有路径数目。
        if(root == nullptr) return 0;

        int ret = rootSum(root, targetSum);
        ret += pathSum(root->left, targetSum);
        ret += pathSum(root->right, targetSum);

        return ret;
    }

    //思路2  前缀和
    /* 
    在同一个路径之下（可以理解成二叉树从root节点出发，到叶子节点的某一条路径），如果两个数的前缀总和是相同的，那么这些节点之间的元素总和为零。
    进一步扩展相同的想法，如果前缀总和currSum，在节点A和节点B处相差target，则位于节点A和节点B之间的元素之和是target。

    因为本题中的路径是一棵树，从根往任一节点的路径上(不走回头路)，有且仅有一条路径，因为不存在环。(如果存在环，前缀和就不能用了，需要改造算法)
    抵达当前节点(即B节点)后，将前缀和累加，然后查找在前缀和上，有没有前缀和currSum-target的节点(即A节点)，存在即表示从A到B有一条路径之和满足条件的情况。
    结果加上满足前缀和currSum-target的节点的数量。然后递归进入左右子树。
    左右子树遍历完成之后，回到当前层，需要把当前节点添加的前缀和去除。避免回溯之后影响上一层。因为思想是前缀和，不属于前缀的，我们就要去掉它。
     */


    /* 
     *从当前节点反推到根节点(反推比较好理解，正向其实也只有一条)，有且仅有一条路径，因为这是一棵树
     * 如果此前有和为currSum-target,而当前的和又为currSum,两者的差就肯定为target了
     * 所以前缀和对于当前路径来说是唯一的，当前记录的前缀和，在回溯结束，回到本层时去除，保证其不影响其他分支的结果
     */
    unordered_map<long long, int> prefix;//key 是前缀和 ， value 是大小为key的前缀和出现的次数
    int dfs(TreeNode* root, long long curr, int targetSum){
        //递归终止条件
        if(root == nullptr) return 0;
        //递归循环主体
        int ret = 0;
        //记录当前路径到该节点的路径和
        curr += root->val;
        //首先看一下当前路径是否存在 curr-targetSum的前缀和，如果存在则从上一个curr-targetSum前缀和到当前节点的curr前缀和之间的路径就是和为targetSum的路径。
        if(prefix.count(curr - targetSum)){
            ret = prefix[curr-targetSum];
        }
        prefix[curr] ++;//更新路径上当前节点前缀和curr的个数
        ret += dfs(root->left, curr, targetSum);
        ret += dfs(root->right, curr, targetSum);
        prefix[curr]--;

        return ret;
    }
    int pathSum(TreeNode* root, int targetSum){
        prefix[0] = 1;
        return dfs(root, 0, targetSum);
    }
};