class Solution:
    def helper(self, nums: List[int], i: int, dp:List[int]) -> int:
        if i >= len(nums):
            return 0

        if dp[i] != -1:
            return dp[i]

        pick = nums[i] + self.helper(nums, i+2, dp)
        unpick = self.helper(nums, i+1, dp)

        dp[i] = max(pick, unpick)

        return dp[i]
    def rob(self, nums: List[int]) -> int:
        dp = [-1] * (len(nums)+1)
        return self.helper(nums, 0, dp)