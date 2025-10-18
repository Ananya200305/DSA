class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        charST = {}
        charTS = {}

        for i in range(len(s)):
            charS = s[i]
            charT = t[i]

            if charS in charST and charST[charS] != charT:
                return False
            else:
                charST[charS] = charT

            if charT in charTS and charTS[charT] != charS:
                return False
            else:
                charTS[charT] = charS
            
        return True