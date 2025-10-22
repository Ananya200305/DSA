class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        prod = nums[0]
        maxProd = nums[0]

        for i in range(1, len(nums)):
            if prod == 0:
                prod = nums[i]
            else:
                prod = prod * nums[i]

            maxProd = max(maxProd, prod)

        print(maxProd)

        prod = nums[len(nums)-1]
        print(prod)
        maxProd = max(prod, maxProd)
        print(maxProd)

        for i in range(len(nums)-2, -1, -1):
            if prod == 0:
                prod = nums[i]
            else:
                prod = prod * nums[i]

            maxProd = max(maxProd, prod)

        return maxProd



