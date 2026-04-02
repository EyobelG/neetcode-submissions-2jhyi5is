class Solution {
public:
    bool isAnagram(string s, string t) {
       // base case (check if the strings are equal length)
       // If not then they can't be anagrams of each other
       if (s.length() != t.length()) {
        return false;
       }

       unordered_map<char,int> s_counts;
       unordered_map<char,int> t_counts;

       for (char c : s) {
        s_counts[c]++;
       }

       for (char c : t) {
        t_counts[c]++;
       }
       return s_counts == t_counts;
         
    }
};
