class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        # Base Case
        if not intervals:
            return []
        # Sort and Init Result
        intervals.sort()
        result = []
        result.append(intervals[0])
        # Loop through Interval begining from idx 1
        for i in range(1, len(intervals)):
            # Get most recently added interval in result list
            lastMerged = result[-1]
               
            # Check for overlap:
            # If the current interval's START time is less than or equal to 
            # the last merged interval's END time, they overlap.
         
            # Merge them by updating the END time of the last merged interval.
            if intervals[i][0] <= lastMerged[1]:
                lastMerged[1] = max(lastMerged[1], intervals[i][1])
            # No overlap
            else:
                result.append(intervals[i])
        # Return the final list of merged intervals.
        return result


