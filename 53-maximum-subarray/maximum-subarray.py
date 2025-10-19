class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        subsum = nums[0]
        maxSum = nums[0]

        for i in range(1,len(nums)):
            subsum = max(subsum + nums[i], nums[i])
            maxSum = max(subsum, maxSum)

        return maxSum