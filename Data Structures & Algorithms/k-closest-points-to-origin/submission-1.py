import math
import heapq
from typing import List

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        maxHeap = []
        for x, y in points:
            dist = x**2 + y**2
            heapq.heappush(maxHeap, (-dist, [x, y]))
            if len(maxHeap) > k:
                heapq.heappop(maxHeap)
        return [point for dist, point in maxHeap]
"""
import heapq
from typing import List

class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.minHeap = []

        for num in nums:
            heapq.heappush(self.minHeap, num)

            if len(self.minHeap) > self.k:
                heapq.heappop(self.minHeap)
        
    def add(self, val: int) -> int:
        heapq.heappush(self.minHeap, val)
        if len(self.minHeap) > self.k:
            heapq.heappop(self.minHeap)
        
        return self.minHeap[0]
        
"""