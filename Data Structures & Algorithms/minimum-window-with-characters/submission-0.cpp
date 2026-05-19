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



/*
 if (s1.length() > s2.length()) {
            return false;
        }

        vector<int> counts(26, 0);
        int left = 0; // Already declared here!
        int matches = 0;

        for (int i = 0; i < s1.length(); i++) {
            counts[s1[i] - 'a']++;
            counts[s2[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (counts[i] == 0) {
                matches++;
            }
        }

        if (matches == 26) return true;

        // Sliding phase: 'right' starts right after the first window
        // (Removed the duplicate 'int left = 0;' from here)
        for (int right = s1.length(); right < s2.length(); right++) {
            
            // 1. Process the character ENTERING the window from the right
            int r_idx = s2[right] - 'a';
            if (counts[r_idx] == 0) matches--; 
            counts[r_idx]--;                   
            if (counts[r_idx] == 0) matches++; 

            // 2. Process the character LEAVING the window from the left
            int l_idx = s2[left] - 'a';
            if (counts[l_idx] == 0) matches--; 
            counts[l_idx]++;                   
            if (counts[l_idx] == 0) matches++; 

            // 3. Move the left pointer forward to maintain the fixed window size
            left++;

            // 4. Check if the updated window is a perfect match
            if (matches == 26) {
                return true;
            }
        }

        // If we slide through the whole string without finding a match
        return false;
    }

*/