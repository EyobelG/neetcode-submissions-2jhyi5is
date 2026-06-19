class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        
        while left <= right:
            mid = (left + right) // 2

            if nums[mid] == target:
                return mid
                
            if nums[left] <= nums[mid]:

                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            else:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
        return -1


        



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