class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if (slow == fast) {
                break;
            }
        }

        slow = 0;
        
        while (slow != fast) {
            slow = nums[slow]; //move 1 step
            fast = nums[fast]; //again, 1 step
        }
        
        return slow;
    }
};