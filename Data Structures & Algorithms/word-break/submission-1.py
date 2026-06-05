class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        dp = [False] * (n + 1)
        dp[n] = True

        for i in range(n - 1, -1, -1):
            for word in wordDict:
                if (i + len(word)) <= n and s[i: i + len(word)] == word:
                    dp[i] = dp[i + len(word)]
                if dp[i]:
                    break

        return dp[0]
       



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