class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        ans = set(nums)

        for i in range(1,1000):
            if (k*i) not in ans:
                return (k*i)

        return 0