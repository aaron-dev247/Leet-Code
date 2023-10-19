from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:

        res = []
        subset = []
        
        def backtrac(i):

            if i >= len(nums):
                res.append(subset.copy())
                return
            
            # decision to include nums[i]
            subset.append(nums[i])
            backtrac(i + 1)
            
            # decision to not include nums[i]
            subset.pop()
            backtrac(i + 1)
        
        backtrac(0)
        return res


s = Solution()

s.subsets([1, 2, 3])