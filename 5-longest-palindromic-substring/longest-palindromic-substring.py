class Solution:
    def __init__ (self):
        self.ans = ""
    def expand(self, s:str, left: int, right: int) -> None:
        while left >= 0 and right < len(s):
            if s[left] != s[right]:
                break
            left -= 1
            right += 1

        if len(self.ans) < (right - left):
            self.ans = s[left+1:right]
    def longestPalindrome(self, s: str) -> str:
        for i in range(len(s)):
            self.expand(s, i, i)
            self.expand(s,i, i+1)

        return self.ans