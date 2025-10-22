class Solution:
    def bs(self, nums:List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = left + (right - left)//2

            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                right = mid - 1
            else:
                left = mid + 1
        
        return left

    def lengthOfLIS(self, nums: List[int]) -> int:
        res = []

        for i in range(len(nums)):
            if len(res) == 0 or res[-1] < nums[i]:
                res.append(nums[i])
            else:
                idx = self.bs(res, nums[i])
                res[idx] = nums[i]

        return len(res)