class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:

        def dfs(root, maxVal):
            
            if not root:
                return 0
            res = 1 if maxVal <= root.val else 0
            maxVal = max(maxVal, root.val)
            res += dfs(root.left, maxVal)
            res += dfs(root.right, maxVal)
            return res

        return dfs(root, root.val)

s = Solution()
s.goodNodes(TreeNode(3, TreeNode(3, TreeNode(3), None)))