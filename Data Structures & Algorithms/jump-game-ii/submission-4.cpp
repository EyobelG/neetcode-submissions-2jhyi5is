class Solution {
public:
    int jump(vector<int>& nums) {
        // Entrance
        int jumps = 0;
        int l = 0;
        int r = 0;

        // Guard Room
        while (r < nums.size() - 1){
            // Lookout tower
            int farthest = 0;
            // Scanning
            for (int i = l; i <= r; i++) {
                // Treasure room
                farthest = max(farthest, i + nums[i]);
            }

            // Bridge of boundaries
            l = r + 1;
            r = farthest;
            jumps++;

            // Checkpoint Hall

        }
        // Throne Room
        return jumps;


      
    }
};