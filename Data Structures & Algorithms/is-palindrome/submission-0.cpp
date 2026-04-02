#include <string>
#include <algorithm> // For std::tolower (and others)
#include <cctype>    // For std::isalnum, std::tolower

class Solution {
public:
    bool isPalindrome(std::string s) {
        
        int left = 0;
        int right = s.length() - 1;

        // Loop until the pointers meet or cross
        while (left < right) {
            
            // 1. Move the left pointer past non-alphanumeric characters
            // Use std::isalnum to check for letters OR numbers
            while (left < right && !std::isalnum(s[left])) {
                left++;
            }

            // 2. Move the right pointer past non-alphanumeric characters
            while (left < right && !std::isalnum(s[right])) {
                right--;
            }

            // 3. Compare the current alphanumeric characters (case-insensitive)
            if (left < right) {
                // std::tolower converts a character to its lowercase equivalent
                if (std::tolower(s[left]) != std::tolower(s[right])) {
                    // If the characters don't match, it's not a palindrome
                    return false;
                }
                
                // Move both pointers inward for the next comparison
                left++;
                right--;
            }
        }
        
        // 4. If the loop completes without returning false, it is a palindrome
        return true;
    }
};