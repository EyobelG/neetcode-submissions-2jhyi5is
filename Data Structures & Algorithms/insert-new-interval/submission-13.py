class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        if not intervals:
            return [newInterval]
        i, n = 0, len(intervals)
        newStart, newEnd = newInterval[0], newInterval[1]
        result = []

        while i < n and intervals[i][1] < newStart:
            result.append(intervals[i])
            i += 1
        while (i < n and intervals[i][0] <= newEnd):
            newStart = min(newStart, intervals[i][0])
            newEnd = max(newEnd, intervals[i][1])
            i += 1
        result.append(list([newStart, newEnd]))

        while i < n:
            result.append(intervals[i])
            i += 1
        return result

        