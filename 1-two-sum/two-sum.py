class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        MAP = defaultdict(int)

        for i in range(len(nums)):
            rem = target - nums[i]

            if rem in MAP:
                return [i, MAP[rem]]

            MAP[nums[i]] = i

        return []