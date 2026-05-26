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
                s++;
                count++;
            } else {
                e++;
                count--;
            }
            max_rooms = max(max_rooms, count);
        }

        return max_rooms;

    }
};
