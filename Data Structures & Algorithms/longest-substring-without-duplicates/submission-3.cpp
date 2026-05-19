
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> charSet;
        int l = 0;
        int res = 0;

        for (int r = 0; r < s.length(); r++) {
            // while s[r] is already in the set, remove s[l] and move left pointer
            while (charSet.find(s[r]) != charSet.end()) {
                charSet.erase(s[l]);
                l++;
            }
            // Add the current character and update max length
            charSet.insert(s[r]);
            res = std::max(res, r - l + 1);
        }
        return res;
    }
};