class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) {
            return "";
        }
        if (s == t) {
            return s;
        }
        vector<int> t_counts(128, 0);
        vector<int> window_counts(128, 0);

        int required_matches = 0;
        for (int i = 0; i < t.length(); i++) {

            if (t_counts[t[i]] == 0) {
                required_matches++;
            }
            t_counts[t[i]]++;
        }

        int left = 0;
        int current_matches = 0;
        int min_length = INT_MAX;
        int start_idx = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            window_counts[c]++;

            if (t_counts[c] > 0 && window_counts[c] == t_counts[c]) {
                current_matches++;
            }

            while (current_matches == required_matches) {
                if ((right - left + 1) < min_length) {
                    min_length = right - left + 1;
                    start_idx = left;
            }
            char left_char = s[left];
            window_counts[left_char]--;

            if (t_counts[left_char] > 0 && window_counts[left_char] < t_counts[left_char]) {
                current_matches--;
            }
            left++;
            
            }

        }
        return min_length == INT_MAX ? "" : s.substr(start_idx, min_length);
    }
};
