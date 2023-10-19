from typing import List


class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        
        candidates.sort()
        res = []
        combination = []

        def backtrack(pos, target):
            if target == 0:
                res.append(combination.copy())
                return
            if target < 0:
                return
            
            prev = -1

            for i in range(pos, len(candidates)):

                if candidates[i] == prev:
                    continue
                    
                combination.append(candidates[i])
                backtrack(i + 1, target - candidates[i])

                prev = combination.pop()

        backtrack(0, target)
        return res

s = Solution()
s.combinationSum2([2,5,2,1,2], 5)