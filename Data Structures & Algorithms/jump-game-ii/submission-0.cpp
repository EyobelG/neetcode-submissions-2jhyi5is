class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int l = 0;
        int r = 0;

        // Loop until the right pointer reaches or exceeds the last index
        while (r < nums.size() - 1) {
            int farthest = 0;
            
            // Find the max reachable index from the current window [l, r]
            for (int i = l; i <= r; i++) {
                farthest = max(farthest, i + nums[i]);
             
            }
            // Move the window to the next level
            l = r + 1;
            r = farthest;
            jumps++;
        }
        return jumps;

        

        
    }
};


/*

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > max_reach) {
                return false;
            }
            max_reach = max(max_reach, i + nums[i]);
        }
        return true;
    }
};

*/