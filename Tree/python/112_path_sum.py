from TreeNode import TreeNode

class Solution:
    def hasPathSum(self, root : TreeNode, targerSum : int) -> bool:
        if not root:
            return False
        
        if not root.left and (not root.right) and targerSum == root.val:
            return True

        if root.left:
            targerSum = targerSum - root.val
            if self(root.left, targerSum):
                return True
            targerSum += root.val
        
        