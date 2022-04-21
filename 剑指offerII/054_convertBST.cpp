#include<iostream>
#include"TreeNode.h"

using namespace std;
/* 
给定一个二叉搜索树，请将它的每个节点的值替换成树中大于或者等于该节点值的所有节点值之和。
思路：
遍历节点，对于每个节点单独计算右子树和本身节点的累计和
 */
class Solution{
public:
    int temp_sum;
    void dfs(TreeNode* root){
        if(root == nullptr){
            temp_sum += 0;
            return;
        }

        dfs(root->right);//遍历右子树

        root->val += temp_sum;//当前节点值替换为大于等于该节点值的累计和
        temp_sum = root->val;//第一次出错位置， temp_sum += root->val 不用+=，因为前面的值已经累加到root->val中了

        dfs(root->left);

        return;
    }
    TreeNode* convertBST(TreeNode* root){
        temp_sum = 0;
        dfs(root);
        return root;
    }

/* 
Morris 遍历的核心思想是利用树的大量空闲指针，实现空间开销的极限缩减。其反序中序遍历规则总结如下：

* 如果当前节点的右子节点为空，处理当前节点，并遍历当前节点的左子节点；

* 如果当前节点的右子节点不为空，找到当前节点右子树的最左节点（该节点为当前节点中序遍历的前驱节点）；

    * 如果最左节点的左指针为空，将最左节点的左指针指向当前节点，遍历当前节点的右子节点；

    * 如果最左节点的左指针不为空，将最左节点的左指针重新置为空（恢复树的原状），处理当前节点，并将当前节点置为其左节点；

重复步骤 1 和步骤 2，直到遍历结束。
*/
    TreeNode* getSuccessor(TreeNode* node){//找到node节点的最左节点
        TreeNode* succ = node->right;
        while (succ->left != nullptr && succ->left != node)
        {
            succ = succ->left;
        }
        return succ;
    }
    TreeNode* convertBST2(TreeNode* root){
        int sum = 0;
        TreeNode* node = root;

        while (node != nullptr)
        {
            if(node->right == nullptr){
                sum += node->val;
                node->val = sum;
                node = node->left;
            }else{
                TreeNode* succ = getSuccessor(node);
                if(succ->left == nullptr){
                    succ->left = node;
                    node = node->right;
                }else{
                    succ->left = nullptr;
                    sum += node->val;
                    node->val = sum;
                    node = node->left; 
                }
            }
        }

        return root;
        
    }
};