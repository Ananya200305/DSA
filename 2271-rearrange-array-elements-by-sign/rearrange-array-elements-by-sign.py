class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        positive = []
        negative = []

        for num in nums:
            if num > 0:
                positive.append(num)
            else:
                negative.append(num)

        res = []

        i = 0
        j = 0

        while i < len(positive) and j < len(negative):
            res.append(positive[i])
            i += 1
            res.append(negative[j])
            j += 1

        return res