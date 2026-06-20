import heapq
from collections import Counter, deque
from typing import List

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
    
        # Count the frequencies of each task
        counts = Counter(tasks)
        
        # Extract just the counts (we don't need the task names)
        frequencies = list(counts.values())

        max_heap = [-f for f in frequencies]
        heapq.heapify(max_heap)

        time = 0
        queue = deque()

        while max_heap or queue:
            time += 1
            if max_heap:
                counts = 1 + heapq.heappop(max_heap)
                if counts:
                    queue.append([counts, time + n])
            if queue and queue[0][1] == time:
                heapq.heappush(max_heap, queue.popleft()[0])
        return time
            


        
        
        """
        import heapq

        class Solution:
            def findKthLargest(self, nums: List[int], k: int) -> int:
                maxHeap = [-num for num in nums]
                heapq.heapify(maxHeap)

                for _ in range(k - 1):
                    heapq.heappop(maxHeap)
                return -maxHeap[0]
        """