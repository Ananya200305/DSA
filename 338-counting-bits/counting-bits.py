class Solution:
    def countBits(self, n: int) -> List[int]:
        res = []
        for i in range(n+1):
            count = 0
            temp = i
            while temp > 0:
                if temp % 2 == 1:
                    count += 1
                temp = temp // 2
            res.append(count)
        return res
            