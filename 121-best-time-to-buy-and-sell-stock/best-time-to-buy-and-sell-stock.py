class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minPrice = prices[0]
        maxSum = 0

        l = len(prices)

        for i in range(1,l):
            if minPrice > prices[i]:
                minPrice = prices[i]
            else: 
                maxSum = max(maxSum, prices[i] - minPrice)
        
        return maxSum