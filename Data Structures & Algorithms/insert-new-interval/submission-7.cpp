class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) return {newInterval};

        int i = 0;
        int n = intervals.size();

        int newStart = newInterval[0];
        int newEnd = newInterval[1];

        vector<vector<int>> result;

        result.reserve(2*n + 1);

        while (i < n && intervals[i][1] < newStart) {
            result.push_back(std::move(intervals[i]));
            i++;
        }

        while (i < n && intervals[i][0] <= newEnd) {
            newStart = min(newStart, intervals[i][0]);
            newEnd = max(newEnd, intervals[i][1]);
            i++;
        }
        result.emplace_back(vector<int>{newStart, newEnd});

        while (i < n) {
            result.push_back(std::move(intervals[i]));
            i++;
        }

        return result;

    }
};