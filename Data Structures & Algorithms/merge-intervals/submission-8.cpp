


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // edge case
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        // initialize the result with the first interval
        result.push_back(intervals[0]);
 
        // Process the remaining intervals sequentially
        for (int i = 1; i < intervals.size(); i++) {
            // Get a referene to the last merged interval
            vector<int>& lastMerged = result.back();
            // overlap found
            if (intervals[i][0] <= lastMerged[1]) {
                lastMerged[1] = max(lastMerged[1], intervals[i][1]);
            // no overlap found
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;

    }
};

