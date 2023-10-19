from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0

        left, right = 0, 1

        while right < len(prices):

            # right pointer at lowest price
            if prices[left] > prices[right]:
                left = right
            else:
                profit = max(profit, prices[right] - prices[left])
            
            right += 1
            
        return profit

s = Solution()

s.maxProfit([7,1,5,3,6,4])