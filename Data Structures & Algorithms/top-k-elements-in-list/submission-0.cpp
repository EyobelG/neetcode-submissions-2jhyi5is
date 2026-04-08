class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int n : nums) {
            counts[n]++;
        }

        // Min-heap to store {frequency, value}
        // We want the smallest frequencies at the top so we can pop them
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto const& [val, freq] : counts) {
            pq.push({freq, val});
            if (pq.size() > k) {
                pq.pop(); // Remove the element with the lowest frequency
            }
        }

        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};