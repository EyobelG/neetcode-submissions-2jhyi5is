class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m, n = len(nums1), len(nums2)
        if m > n:
            return self.findMedianSortedArrays(nums2, nums1)
        low, high = 0, m
        totalHalf = (m + n + 1) // 2

        while low <= high:
            partX = (low + high) // 2
            partY = totalHalf - partX

            maxLeftX = float('-inf') if partX == 0 else nums1[partX - 1]
            minRightX = float('inf') if partX == m else nums1[partX]

            maxLeftY = float('-inf') if partY == 0 else nums2[partY - 1]
            minRightY = float('inf') if partY == n else nums2[partY]

            if (maxLeftX <= minRightY and maxLeftY <= minRightX):
                if (m + n) % 2 == 0:
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2
                else:
                    return max(maxLeftX, maxLeftY)
            elif maxLeftX > minRightY:
                high = partX - 1
            else:
                low = partX + 1
        return 0.0
        