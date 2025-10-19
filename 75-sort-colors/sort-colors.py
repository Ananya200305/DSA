class Solution:
    def sortColors(self, nums: List[int]) -> None:
        n = len(nums)
        left = 0
        mid = 0
        right = n-1

        while mid <= right:
            if nums[mid] == 0:
                nums[left], nums[mid] = nums[mid], nums[left]
                left += 1
                mid += 1
            elif nums[mid] == 1:
                mid += 1
            else:
                nums[mid] , nums[right] = nums[right], nums[mid]
                right -= 1


        