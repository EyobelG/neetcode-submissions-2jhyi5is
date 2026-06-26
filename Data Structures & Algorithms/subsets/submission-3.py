class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ret = []
        subset = []
        def dfs(i: int):
            ret.append(subset[:])
            for j in range(i, len(nums)):
                subset.append(nums[j])
                dfs(j+1)
                subset.pop()
        dfs(0)
        return ret