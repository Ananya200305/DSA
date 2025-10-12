class Solution:
    def reverseBits(self, n: int) -> int:
        temp = ""

        while n: 
            temp = str(n%2) + temp 
            n = n // 2

        temp = temp.zfill(32)
        print(temp)

        temp = temp[::-1]

        return int(temp,2)