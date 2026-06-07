class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        intervals.sort()
        result = []
        result.append(intervals[0])
        for i in range(1, len(intervals)):
            lastMerged = result[-1]
            if intervals[i][0] <= lastMerged[1]:
                lastMerged[1] = max(lastMerged[1], intervals[i][1])
            else:
                result.append(intervals[i])
        return result
        