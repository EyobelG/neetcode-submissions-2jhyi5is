class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res = nums[0]
        curMin, curMax = 1, 1
        for i in range(len(nums)):
            if nums[i] == 0:
                curMin, curMax = 0, 0
            pos1 = nums[i]
            pos2 = nums[i] * curMax
            pos3 = nums[i] * curMin
            curMax = max(pos1, pos2, pos3)
            curMin = min(pos1, pos2, pos3)
            res = max(res, curMax)
        return res


        






"""
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [amount + 1] * (amount + 1)
        dp[0] = 0

        for coin in coins:
            for i in range(coin, amount + 1):
                if dp[i - coin] != amount + 1:
                    dp[i] = min(dp[i], dp[i - coin] + 1)

        return -1 if dp[amount] > amount else dp[amount]
        
"""