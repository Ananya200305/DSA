class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minPrice = prices[0]
        maxProfit = 0

        for i in range(len(prices)):
            if minPrice > prices[i]:
                minPrice = prices[i]
            else:
                maxProfit = max(maxProfit, prices[i] - minPrice)
        
        return maxProfit