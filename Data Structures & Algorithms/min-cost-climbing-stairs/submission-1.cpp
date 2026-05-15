class Solution {
    unordered_map<int, int> memo;

public:
    int minCostClimbingStairs(vector<int>& cost) {
        memo.clear();
        // We start the DFS at either index 0 or index 1
        return min(dfs(0, cost), dfs(1, cost));
    }

private:
    int dfs(int i, const vector<int>& cost) {
        // 1. Base Case: If we are at or past the last stair
        if (i >= cost.size()) {
            return 0;
        }

        // 2. Check the memo map
        if (memo.find(i) != memo.end()) {
            return memo[i];
        }

        // 3. Recursive step: Current stair cost + min of next possible steps
        memo[i] = cost[i] + min(dfs(i + 1, cost), dfs(i + 2, cost));

        return memo[i];
    }
};