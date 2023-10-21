
class solution:

    def canSum(self, target, nums: list[int]):
        if target == 0:
            return True
        
        if target < 0:
            return False
        
        for num in nums:
            if self.canSum(target - num, nums):
                return True
        
        return False

s = solution()
print(s.canSum(7, [2, 3]))
print(s.canSum(7, [5, 3, 4, 7]))
print(s.canSum(300, [7, 14]))