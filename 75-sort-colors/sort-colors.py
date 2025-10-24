class Solution:
    def sortColors(self, nums: List[int]) -> None:
        n = len(nums)

        l = 0
        m = 0
        r = n-1

        while m <= r:
            if nums[m] == 0:
                nums[l], nums[m] = nums[m], nums[l]
                l += 1
                m += 1
            elif nums[m] == 1:
                m += 1
            else:
                nums[m], nums[r] = nums[r], nums[m]
                r -= 1
        