class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        count = [0] * 26

        if len(s) != len(t):
            return False

        for i in range(len(s)):
            count[ord(s[i]) - ord('a')] += 1
            count[ord(t[i]) - ord('a')] -= 1

        for c in count:
            if c > 0 or c < 0:
                return False
        
        return True