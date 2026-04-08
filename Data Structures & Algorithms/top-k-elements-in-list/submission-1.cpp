class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        // Buckets where index is the frequency
        // We need n + 1 size because a number could appear n times
        vector<vector<int>> buckets(n + 1);
        for (auto const& [val, freq] : counts) {
            buckets[freq].push_back(val);
        }

        vector<int> result;
        // Search from highest frequency to lowest
        for (int i = n; i >= 0 && result.size() < k; i--) {
            for (int val : buckets[i]) {
                result.push_back(val);
                if (result.size() == k) return result;
            }
        }
        return result;
    }
};