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
        



    #   cost.append(0)
    #     # 2. Iterate backwards from the second to last actual stair down to index 0. len(cost) - 3 is the first index from the right that has both (i + 1) and (i + 2) available.
    #     for i in range(len(cost) - 3, -1, -1):
    #         # 3. For current step i, add the minimum of the two future paths you can take: either taking 1 step to (i + 1) or taking 2 steps to (i + 2).
    #         cost[i] += min(cost[i + 1], cost[i + 2])
    #     # 4. Since you are allowed to start at either index 0 or index 1, return the smaller total cost between starting at step 0 vs. step 1.
    #     return min(cost[0], cost[1])