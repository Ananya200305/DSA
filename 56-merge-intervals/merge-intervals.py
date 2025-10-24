class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x:x[0])

        prev = intervals[0]

        res = []

        for i in range(1,len(intervals)):
            interval = intervals[i]

            if prev[1] >= interval[0]:
                prev[1] = max(prev[1], interval[1])
            else:
                res.append(prev)
                prev = interval

        res.append(prev)

        return res

