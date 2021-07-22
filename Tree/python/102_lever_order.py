from typing import List
from TreeNode import TreeNode

class Solution:
    def levelOrder(self, root:TreeNode) -> List[List[int]]:
        if not root:
            return []
        
        queue = [root]
        out_list = []

        while queue:
            level_size = len(queue)
            in_list = []
            for i in range(level_size):
                curr = queue.pop(0)
                in_list.append(curr.val)
                if curr.left : queue.append(curr.left)
                if curr.right : queue.append(curr.right)
            out_list.append(in_list)
        
        return out_list
                