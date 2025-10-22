class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        freq = {}
        left = 0
        maxLen = 0

        for right in range(len(s)):
            ch = s[right]

            if ch in freq and freq[ch] >= left:
                left = freq[ch] + 1
            
            maxLen = max(maxLen, (right - left + 1))

            freq[ch] = right

        return maxLen