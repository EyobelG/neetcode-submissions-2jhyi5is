class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        minPrice, maxProfit = prices[0], 0
        for i in range(len(prices)):
            curProfit = prices[i] - minPrice

            if curProfit > maxProfit:
                maxProfit = curProfit
            
            if prices[i] < minPrice:
                minPrice = prices[i]
        return maxProfit
        