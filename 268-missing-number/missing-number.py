class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)

        original = (n*(n+1))//2

        sumOfTheList = 0

        for i in nums:
            sumOfTheList += i
        
        ans = original - sumOfTheList

        return ans