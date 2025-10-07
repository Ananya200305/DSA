class Solution:
    def reverseBits(self, n: int) -> int:
        res = ""

        while n > 0:
            res = str(n % 2) + res
            n = n // 2

        res = res.zfill(32)

        res = res[::-1]

        return int(res,2)