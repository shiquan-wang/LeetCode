from typing import List
from TreeNode import TreeNode

class Solution:
    def inorder(self, root:TreeNode, res:List[int]):
        if not root:
            return
        self.inorder(root.left, res)
        res.append(root.val)
        self.inorder(root.right, res)
        

    def inorderTraversal(self, root:TreeNode)->List[int]:
        res = []
        self.inorder(root, res)
        return res
    
    

        