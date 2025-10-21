class Solution:
    def maxDepth(self, s: str) -> int:
        count = 0
        freq = []

        for i in s:
            if i == "(":
                count += 1
                freq.append(count)
            
            if i == ")":
                count -= 1

        maxEle = float('-inf')

        if len(freq) == 0:
            return 0

        for i in freq:
            if i > maxEle:
                maxEle = i

        return maxEle
