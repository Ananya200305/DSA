class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSum = nums[0]
        sumArr = nums[0]

        l = len(nums)

        for i in range(1,l):
            sumArr = max(sumArr+nums[i], nums[i])
            maxSum = max(maxSum, sumArr)
        
        return maxSum
