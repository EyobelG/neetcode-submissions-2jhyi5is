class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        int n = word.length();

        // Optimization 1: Length check
        if (n > rows * cols) return false;

        // Optimization 2: Frequency check
        unordered_map<char, int> count;
        for (const auto& row : board) {
            for (char c : row) count[c]++;
        }
        
        for (char c : word) {
            if (--count[c] < 0) return false;
        }

        // Optimization 3: Heuristic Reverse
        // Start from the end if the suffix is rarer than the prefix
        int first = count[word[0]];
        int last = count[word[n - 1]];
        if (first > last) {
            reverse(word.begin(), word.end());
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (backtrack(board, word, r, c, 0)) return true;
            }
        }
        return false;
    }

private:
    bool backtrack(vector<vector<char>>& board, const string& word, 
                   int r, int c, int index) {
        if (index == word.size()) return true;

        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() ||
            board[r][c] != word[index]) {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#'; // Mark visited

        // Check directions
        bool found = backtrack(board, word, r + 1, c, index + 1) ||
                     backtrack(board, word, r - 1, c, index + 1) ||
                     backtrack(board, word, r, c + 1, index + 1) ||
                     backtrack(board, word, r, c - 1, index + 1);

        board[r][c] = temp; // Backtrack
        return found;
    }
};