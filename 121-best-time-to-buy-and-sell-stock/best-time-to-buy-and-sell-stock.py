class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minPrice = prices[0]
        maxProfit = 0

        for price in prices:
            if price < minPrice:
                minPrice = price
            else:
                maxProfit = max(maxProfit, price - minPrice)

        return maxProfit