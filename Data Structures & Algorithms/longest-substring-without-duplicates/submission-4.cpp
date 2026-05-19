class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Keeps track of the count of each char within the current window
        unordered_map <char, int> counts;
        int maxLength = 0;
        int left = 0; // Left boundary of the sliding window

        // Expand the window by moving the right boundary
        for (int right = 0; right < s.size(); right++) {
            char currChar = s[right];

            // If the character already exists in the window, it is a duplicate
            // Shrink the window from the left until the duplicate is removed.
            while (counts[currChar] > 0) {
                counts[s[left]]--; // Remove the leftmost character form the frequency map.
                left++; // Move the left pointer inward.
            }

            // Include the current character in the window
            counts[currChar]++;

            // Update the maximum length found so far
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;

    }
};