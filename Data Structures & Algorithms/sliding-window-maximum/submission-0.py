import heapq

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:

        left = 0
        maxHeap = []
        output = []

        for right, num in enumerate(nums):
            heapq.heappush(maxHeap, (-num, right))
            
            while maxHeap[0][1] < left:
                heapq.heappop(maxHeap)

            if right >= k - 1:
                output.append(-maxHeap[0][0])
                left += 1
        return output














        """
        class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        counts = {}
        maxCount = left = maxLength = 0

        for right in range(len(s)):
            # Use s[right] instead of char, and assign it back to the dictionary
            counts[s[right]] = counts.get(s[right], 0) + 1
            maxCount = max(maxCount, counts[s[right]])
            
            while (right - left + 1) - maxCount > k:
                counts[s[left]] -= 1
                left += 1
                
            maxLength = max(maxLength, right - left + 1)
            
        return maxLength

        """