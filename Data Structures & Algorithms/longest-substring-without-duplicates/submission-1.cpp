class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char, int> counts;
        int maxLength = 0;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            char currChar = s[right];
            while (counts[currChar] > 0) {
                counts[s[left]]--;
                left++;
            }

            counts[currChar]++;
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;

    }
};