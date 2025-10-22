class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = [0]*26
        maxCount = 0
        maxLen = 0
        left = 0

        for right in range(len(s)):
            count[ord(s[right]) - ord('A')] += 1
            maxCount = max(maxCount, count[ord(s[right])-ord('A')])

            if (right - left + 1) - maxCount > k:
                count[ord(s[left]) - ord('A')] -= 1
                left += 1

            maxLen = max(maxLen, (right- left + 1))

        return maxLen