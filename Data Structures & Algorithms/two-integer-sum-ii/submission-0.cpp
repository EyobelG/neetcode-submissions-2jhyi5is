class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;               // Standard 0-based start
        int right = numbers.size() - 1; // Standard 0-based end

        while (left < right) {
            int currentSum = numbers[left] + numbers[right];

            if (currentSum == target) {
                // Return 1-indexed results by adding 1 to the 0-based indices
                return {left + 1, right + 1};
            } 
            else if (currentSum > target) {
                // Sum is too high, move the right pointer left to decrease it
                right--;
            } 
            else {
                // Sum is too low, move the left pointer right to increase it
                left++;
            }
        }
        
        return {}; // Return empty if no solution is found
    }
};