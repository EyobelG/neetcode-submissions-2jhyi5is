class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        memo = [[-1] * (n + 1) for _ in range(m+1)]
        def solve(m, n):
            if m == 1 or n == 1:
                return 1
            if memo[m][n] != -1:
                return memo[m][n]
            memo[m][n] = solve(m - 1, n) + solve(m, n-1)
            return memo[m][n]
        return solve(m, n)
