class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        size_t rows = matrix.size();
        size_t cols = matrix[0].size();
        int top = 0;
        int bot = static_cast<int>(rows) - 1;

        // Binary search to find the correct row
        while (top <= bot) {
            int row = (top + bot) / 2;
            if (target > matrix[row][cols - 1]) { 
                top = row + 1;
            } else if (target < matrix[row][0]) {
                bot = row - 1;
            } else {
                break;  
            }
        }

        if (top > bot) {  
            return false;
        }
        
        int row = (top + bot) / 2;
        int l = 0;
        int r = static_cast<int>(cols) - 1;
        
        // Binary search within the row
        while (l <= r) {
            int m = (l + r) / 2;
            if (target > matrix[row][m]) {
                l = m + 1;
            } else if (target < matrix[row][m]) {
                r = m - 1;
            } else {
                return true;
            }
        }
        
        return false;
    }
};