class Solution:
    def climbStairs(self, n: int) -> int:
        memo = {}
        def helper(steps: int) -> int:   
            if steps <= 1:
                return 1
            if steps in memo:
                return memo[steps]
            
            memo[steps] = helper(steps - 1) + helper(steps - 2)
            return memo[steps]
        return helper(n)
        
        