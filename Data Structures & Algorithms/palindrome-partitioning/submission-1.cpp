class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        backtrack(s, 0, current, result);
        return result;
    }
private:
    void backtrack(const string& s, int start, vector<string>& current, vector<vector<string>>& result) {
        if (start == s.size()) {
            result.push_back(current);
            return;
        }

        for (int end = start + 1; end <= s.size(); end++) {
            string sub = s.substr(start, end - start);
            if (isPalindrome(sub)) {
                current.push_back(sub);
                backtrack(s, end, current, result);
                current.pop_back();
            }
            
        }
    }

     bool isPalindrome(const string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};
