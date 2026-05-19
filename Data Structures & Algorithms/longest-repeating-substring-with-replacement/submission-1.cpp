using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> counts;
        int maxCount = 0;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.size(); right++) {
            counts[s[right]]++;

            maxCount = max(maxCount, counts[s[right]]);

            while ((right - left + 1) - maxCount > k) {
                counts[s[left]]--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);

        }
        return maxLength;
    }
};
