class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        // Stores the smallest tail of all increasing subsequences found so far
        vector<int> tails;

        for (int x : nums) {
            // Find the first element in tails that is >= x
            auto it = lower_bound(tails.begin(), tails.end(), x);

            if (it == tails.end()) {
                // Base/Extension Case: x is larger than all elements in tails
                tails.push_back(x);
            } else {
                // Replacement Case: x can optimize an existing subsequence tail
                *it = x;
            }
        }

        // The size of the tails vector is the length of the LIS
        return tails.size();
    }
};