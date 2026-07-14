class Solution:
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
        