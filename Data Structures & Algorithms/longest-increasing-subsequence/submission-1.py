import bisect
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        tails = []
        for x in nums:
            idx = bisect.bisect_left(tails, x)

            if idx == len(tails):
                tails.append(x)
            else:
                tails[idx] = x
            
        return len(tails)
