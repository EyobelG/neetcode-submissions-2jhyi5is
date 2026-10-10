class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        subset = []
        def dfs(i):
            # Base case: reached the end of nums, snapshot
            if i >= len(nums):
                res.append(subset.copy())
                return 
            # Decision 1: Include nums[i]
            subset.append(nums[i])
            dfs(i + 1)
            # Backtrack: Remove nums[i] to explore alternative branch
            subset.pop()
            # Decision 2: Exclude nums[i]
            dfs(i + 1)
        dfs(0)
        return res