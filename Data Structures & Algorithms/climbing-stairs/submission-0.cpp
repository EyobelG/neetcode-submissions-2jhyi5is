class Solution {
unordered_map<int, int>memo;
public:
    int climbStairs(int n) {
        if (n == 0) {
            return 1;
        } else if (n == 1)  {
            return 1;
        } 

        if (memo.find(n) != memo.end()) {
            return memo[n];
        }
        memo[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return memo[n];
    
    }
};
