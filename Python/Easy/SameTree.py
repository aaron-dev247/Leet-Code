from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        
        stackP = [p]
        stackQ = [q]

        while stackP and stackQ:
            nodeP = stackP.pop()
            nodeQ = stackQ.pop()
            
            if not nodeP and nodeQ or nodeP and not nodeQ:
                return False
            
            if nodeP and nodeQ:
                if nodeP.val != nodeQ.val:
                    return False
                stackP.append(nodeP.left)
                stackP.append(nodeP.right)
                stackQ.append(nodeQ.left)
                stackQ.append(nodeQ.right)

        return True