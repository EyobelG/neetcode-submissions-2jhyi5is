class Solution {
public:
    string longestPalindrome(string s) {
        // Track the start index and length of the longest palindrome found
        int start = 0;
        int length = s.size();
        int pali_length = 0;
        
        // For each possible center position in the string:
        for (int i = 0; i < length; i++) {
        
                int len1 =  expandAroundCenter(s,  i,  i);
                int len2 =  expandAroundCenter(s, i, i + 1);
                int maxLen = max(len1, len2);
                if (maxLen > pali_length) {
                    pali_length = maxLen;
                    start  = i - (maxLen - 1) / 2;
                }
        }
         
            // Expand around center for odd-length palindromes (single character center)
            
            // Expand around center for even-length palindromes (between two characters)
            
            // Update longest if either expansion found a longer palindrome
    
        
        return s.substr(start, pali_length);
        // Return substring using the tracked start and length
    }
private:
    int expandAroundCenter(const string& s, int left, int right) {
        // While left and right are in bounds AND characters at left and right match:
        while (left >= 0 && left < s.size() &&
               s[left] == s[right]) {
                    left--;
                    right++;
               }
            return right - left - 1;
            // Move left pointer one step left
            
            // Move right pointer one step right
        
        // After loop breaks, calculate and return the length of the palindrome
        // Length = right - left - 1 (because we went one step too far)
        
    }
    
};
