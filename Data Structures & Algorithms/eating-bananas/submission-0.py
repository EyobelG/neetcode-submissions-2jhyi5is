import math

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        # h = num of hours you have to eat all the bananas
        # piles[i] is the number of bananas in the ith pile
        # rate of eating: k (banana/ per hour)
        low, high = 1, max(piles)
        res = high

        while low <= high:
            mid = (low + high) // 2

            total = 0
            for pile in piles:
                total += math.ceil(pile / mid)
            
            if total <= h:
                res = mid
                high = mid - 1
            else:
                low = mid + 1
        return res
            


 




"""

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        low, s = 0, len(nums)
        high = s - 1

        while low <= high:
            mid = (low + high) // 2
            if (nums[mid] == target):
                return mid
            elif nums[mid] < target:
                low = mid + 1
            else:
                high = mid - 1
        return -1
        

"""