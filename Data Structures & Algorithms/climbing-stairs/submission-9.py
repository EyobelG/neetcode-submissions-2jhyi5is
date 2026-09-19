class Solution:
    def __init__(self):
        self.memo = {}
    def climbStairs(self, n: int) -> int:
        # you can climb with either 1 or 2 steps at a time
        # we must return the # of distinct ways to climb to the top of 
        # the staircase... sum of steps should get to n.
        if n <= 1:
            return 1
        
        if n in self.memo:
            return self.memo[n]
        self.memo[n] = self.climbStairs(n - 1) + self.climbStairs(n - 2)
        return self.memo[n]        
        
