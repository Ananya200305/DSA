class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        abc = set(nums)

        maxLen = 0

        for i in abc:
            first = i
            if (first - 1) not in abc:
                length = 1
                while (first + length) in abc:
                    length += 1
                maxLen = max(maxLen, length)
        
        return maxLen
