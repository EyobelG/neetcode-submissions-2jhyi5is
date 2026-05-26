class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) return {newInterval};

        int i = 0;
        int n = intervals.size();

        int newStart = newInterval[0];
        int newEnd = newInterval[1];

        vector<vector<int>> result;
        while (i < n && intervals[i][1] < newStart) {
            result.push_back(intervals[i]);
            i++;

        }

        while (i < n && intervals[i][0] <= newEnd) {
            newStart = min(newStart, intervals[i][0]);
            newEnd = max(newEnd, intervals[i][1]);
            i++;
        }
        result.push_back({newStart, newEnd});

        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};


/*
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end());

        int count = 0;
        int prevEnd = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= prevEnd) {
                prevEnd = intervals[i][1];
            } else {
                count++;
                prevEnd = min(prevEnd, intervals[i][1]);
            }
        }
        return count;

    }
};


*/