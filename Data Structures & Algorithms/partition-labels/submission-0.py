class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        lastIndex = {} # char ==> Last index in the string s
        for i, c in enumerate(s):
            lastIndex[c] = i
        res = []
        size, end = 0, 0
        for i, c in enumerate(s):
            size += 1
            end = max(end, lastIndex[c])

            if i == end:
                res.append(size)
                size = 0
        return res




"""
def maxSubArray(self, nums: List[int]) -> int:
    if len(nums) == 1:
        return nums[0]
    
    curMax, maxEndingHere = nums[0], 0

    for i in range(len(nums)):
        maxEndingHere += nums[i]
        if curMax < maxEndingHere:
            curMax = maxEndingHere
        if maxEndingHere < 0:
            maxEndingHere = 0
    return curMax
    
"""