class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        operators = {
            '+': lambda a, b: b + a,
            '-': lambda a, b: b - a,
            '*': lambda a, b: b * a,
            '/': lambda a, b: int(b / a)
        }
        numStack = []
        for c in tokens:
            if c not in operators.keys():
                numStack.append(int(c))
                continue
            
            numStack.append(operators[c](numStack.pop(), numStack.pop()))
        return numStack[0]

s = Solution()
print(s.evalRPN(["10","6","9","3","+","-11","*","/","*","17","+","5","+"]))