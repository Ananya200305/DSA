class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        subArr = nums[0]
        maxSub = nums[0]

        for i in range(1,len(nums)):
            subArr = max(nums[i], nums[i]+subArr)
            maxSub = max(maxSub, subArr)

        return maxSub