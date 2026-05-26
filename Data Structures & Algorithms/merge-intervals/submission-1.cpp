class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
     
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        //result.reserve(n + 1);
        result.push_back(intervals[0]);
 

        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& lastMerged = result.back();
            
            if (intervals[i][0] <= lastMerged[1]) {
                lastMerged[1] = max(lastMerged[1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;

    }
};



/*
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) return {newInterval};

        int i = 0;
        int n = intervals.size();

        int newStart = newInterval[0];
        int newEnd = newInterval[1];

        vector<vector<int>> result;

        result.reserve(n + 1);

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