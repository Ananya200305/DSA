class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        count = 0

        res = ""

        for i in range(1,len(s)):
            if s[i] == "(":
                count += 1

            if count != 0:
                res += s[i]
            
            if s[i] == ")":
                count -= 1

        return res