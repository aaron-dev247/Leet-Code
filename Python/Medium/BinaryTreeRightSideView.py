from typing import Optional, List
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        
        res = []
        queue = deque([root])
        flag = True

        while queue:

            for i in range(len(queue)):
                node = queue.popleft()
                if node:
                    if flag:
                        res.append(node.val)
                        flag = False
                    queue.append(node.right)
                    queue.append(node.left)

            flag = True
        
        return res

s = Solution()
s.rightSideView(TreeNode(1, TreeNode(2), TreeNode(3)))