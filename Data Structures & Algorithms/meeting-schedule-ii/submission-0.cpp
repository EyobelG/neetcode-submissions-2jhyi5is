/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;

        vector<int> start_times;
        vector<int> end_times;

        for (const auto& i : intervals) {
            start_times.push_back(i.start);
            end_times.push_back(i.end);
        }

        sort(start_times.begin(), start_times.end());
        sort(end_times.begin(), end_times.end());

        int s = 0;
        int e = 0;

        int count = 0;
        int max_rooms = 0;

        while (s < intervals.size()) {
            if (start_times[s] < end_times[e]) {
                count++;
                s++;
            } else {
                count--;
                e++;
            }
            max_rooms = max(max_rooms, count);
        }
        return max_rooms;

    }
};


/*


class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < intervals[i - 1].end) {
                return false;
            }
        }
        return true;
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