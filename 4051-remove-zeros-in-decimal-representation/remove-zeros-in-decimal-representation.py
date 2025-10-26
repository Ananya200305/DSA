class Solution:
    def removeZeros(self, n: int) -> int:
        n = str(n)

        res = ""

        for i in n:
            if i != "0":
                res += i

        return int(res)