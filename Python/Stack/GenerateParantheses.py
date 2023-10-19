from ast import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        # only add open parenthesis if openCount < n
        # only add close parathesis if closeCount < openCount
        # valid <=> openCount == closeCount == n

        stack = []
        result = []
        
        def backtrack(openCount, closeCount):
            if closeCount == n:
                result.append("".join(stack))
                return
            
            if openCount < n:
                stack.append('(')
                backtrack(openCount + 1, closeCount)
                stack.pop()
            
            if closeCount < openCount:
                stack.append(')')
                backtrack(openCount, closeCount + 1)
                stack.pop()
        
        backtrack(0, 0)

        return result