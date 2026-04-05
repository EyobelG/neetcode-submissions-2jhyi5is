class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 1. Pre-allocate memory to avoid re-hashing
        unordered_map<string, vector<string>> groups;
        groups.reserve(strs.size());

        for (const string& s : strs) {
            // 2. Use a fixed-size array for counting
            char count[26] = {0}; 
            for (char c : s) {
                count[c - 'a']++;
            }

            // 3. Create a raw 26-byte string as the key 
            // This is much faster than using to_string() or "#" delimiters
            string key(count, 26);
            groups[key].push_back(s);
        }

        // 4. Use move semantics to build the final result without copying
        vector<vector<string>> result;
        result.reserve(groups.size());
        for (auto& pair : groups) {
            result.push_back(std::move(pair.second));
        }

        return result;
    }
};