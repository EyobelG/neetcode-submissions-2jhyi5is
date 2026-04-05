class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        return solve(m, n, memo);
    
    }
private: 
    int solve(int m, int n, vector<vector<int>>& memo) {
        // base case: getting to row 1, col 1 only has one way of doing so
        if (m == 1 || n == 1) {
            return 1;
        }
        // return value from memoizaiton table if we have solved this prob before
        if (memo[m][n] != -1) {
            return memo[m][n];
        }
        // inductive step (recursion)
        return memo[m][n] = solve(m - 1, n, memo) + solve(m, n - 1, memo);

    }
};
