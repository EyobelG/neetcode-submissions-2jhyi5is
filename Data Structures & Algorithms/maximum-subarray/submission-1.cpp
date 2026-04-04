class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int curMax = nums[0];
        int maxEndingHere = 0;
        for (int i = 0; i < nums.size(); i++) {
            // if (nums[i] > curMax) {
            //     curMax = nums[i];
            // }
            maxEndingHere += nums[i];
            if (curMax < maxEndingHere) {
                curMax = maxEndingHere;
            }
            if (maxEndingHere < 0) {
                maxEndingHere = 0;
            }

        }
        return curMax;


    }
};


