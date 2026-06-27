class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        result = []
        current = []

        def dfs(start, target):
            if target == 0:
                result.append(current[:])
                return
            for i in range(start, len(candidates)):
                if (i > start and candidates[i] == candidates[i - 1]):
                    continue
                if (candidates[i] > target):
                    break
                
                current.append(candidates[i])
                dfs(i + 1, target - candidates[i])
                current.pop()
        dfs(0, target)
        return result
                
        