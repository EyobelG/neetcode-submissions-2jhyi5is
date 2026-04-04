class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int count = 0;

        for (int num : nums) {
            if (numSet.find(num - 1) == numSet.end()) {
                int curNum = num;
                int curCount = 1;
                while (numSet.find(curNum + 1) != numSet.end()) {
                    curNum += 1;
                    curCount++;
                }
                count = max(curCount, count);
            }
        }
        return count;
    }
};
