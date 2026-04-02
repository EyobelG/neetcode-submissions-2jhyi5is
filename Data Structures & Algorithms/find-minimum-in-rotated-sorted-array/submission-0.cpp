class Solution {
public:
    int findMin(vector<int> &nums) {

        if (nums.size() == 1) {
            return nums[0];
        }
        int mid = nums.size() / 2;
        int left = 0;
        int right = nums.size() - 1;

        if (mid > 0 && nums[mid] < nums[mid - 1]) {
            return nums[mid];
        }

        if (nums[mid] > nums[right]) {
            vector<int> right_half(nums.begin() + mid + 1, nums.end());
            return findMin(right_half);
        } else {
            vector<int> left_half(nums.begin(), nums.begin() + mid);
            return findMin(left_half);
        }
    }
    
};
