class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        prod = nums[0]
        maxProd = nums[0]

        for i in range(1,len(nums)):
            if prod == 0:
                prod = nums[i]
            else:
                prod *= nums[i]
            maxProd = max(maxProd, prod)

        prod = nums[len(nums)-1]
        maxProd = max(maxProd, prod)

        for i in range(len(nums)-2, -1, -1):
            if prod == 0:
                prod = nums[i]
            else:
                prod *= nums[i]
            maxProd = max(maxProd, prod)

        return maxProd