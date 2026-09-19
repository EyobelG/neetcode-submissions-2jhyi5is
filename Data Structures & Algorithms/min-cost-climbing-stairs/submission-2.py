class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        # 1. Append 0 to represent the target destination floor (the top of the stairs). Reaching this point costs nothing extra.
        cost.append(0)
        # 2. Iterate backwards from the second to last actual stair down to index 0. len(cost) - 3 is the first index from the right that has both (i + 1) and (i + 2) available.
        for i in range(len(cost) - 3, -1, -1):
            # 3. For current step i, add the minimum of the two future paths you can take: either taking 1 step to (i + 1) or taking 2 steps to (i + 2).
            cost[i] += min(cost[i + 1], cost[i + 2])
        # 4. Since you are allowed to start at either index 0 or index 1, return the smaller total cost between starting at step 0 vs. step 1.
        return min(cost[0], cost[1])