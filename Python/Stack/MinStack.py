class MinStack(object):

    def __init__(self):
        self.minValArray = []
        self.stackArray = []

    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        self.stackArray.append(val)
        self.minValArray.append(min(val, self.minValArray[-1] if self.minValArray else val))
        
    def pop(self):
        """
        :rtype: None
        """
        self.stackArray.pop()
        self.minValArray.pop()

    def top(self):
        """
        :rtype: int
        """
        return self.stackArray[-1]

    def getMin(self):
        """
        :rtype: int
        """
        return self.minValArray[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()