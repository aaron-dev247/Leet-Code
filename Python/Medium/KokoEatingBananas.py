import math
from typing import List


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:

        left, right = 1, max(piles)

        k = right

        while left <= right:
            mid = left + (right - left) // 2

            hours = 0
            for i in range(len(piles)):
                hours += math.ceil(piles[i] / mid)

            if hours > h:
                left = mid + 1
            else:
                k = min(k, mid)
                right = mid - 1

        return k