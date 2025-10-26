class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        A = sorted(a*a for a in nums)

        count = sum(A)
        half = len(A)//2
        res = sum(A[half:len(A)]) - sum(A[0:half])

        return res
