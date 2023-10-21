from typing import List
import heapq


class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        # multiply by -1 to work around min heap
        maxHeap = [-s for s in stones]
        heapq.heapify(maxHeap)

        while len(maxHeap) > 1:
            stone1, stone2 = heapq.heappop(maxHeap), heapq.heappop(maxHeap)
            if stone2 > stone1:
                heapq.heappush(maxHeap, stone1 - stone2)

        if len(maxHeap) == 0:
            return 0
        return maxHeap[0] * -1