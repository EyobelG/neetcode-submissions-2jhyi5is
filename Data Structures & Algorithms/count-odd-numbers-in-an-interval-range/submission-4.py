class Solution:
    def countOdds(self, low: int, high: int) -> int:
        # Count
        x = (high + 1) // 2
        y = low // 2
        return x - y
        