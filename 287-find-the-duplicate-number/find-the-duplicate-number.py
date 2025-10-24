class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        n = len(nums)

        freq = [0] * n

        for i in range(len(nums)):
            freq[nums[i]] += 1

        for i in range(len(freq)):
            if freq[i] >= 2:
                return i

        return 0