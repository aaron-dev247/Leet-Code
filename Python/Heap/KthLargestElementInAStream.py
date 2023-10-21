import heapq
from typing import List


class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        # minHeap with K largest integers
        self.k, self.mindHeap = k, nums
        heapq.heapify(self.mindHeap)
        while len(self.mindHeap) > k:
            heapq.heappop(self.mindHeap)

    def add(self, val: int) -> int:
        heapq.heappush(self.mindHeap, val)
        if len(self.mindHeap) > self.k:
            heapq.heappop(self.mindHeap)
        # heap store smallest item is at [0]
        return self.mindHeap[0]