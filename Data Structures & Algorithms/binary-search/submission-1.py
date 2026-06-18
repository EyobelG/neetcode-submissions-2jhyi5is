class Solution:
    def search(self, nums: List[int], target: int) -> int:
        low, s = 0, len(nums)
        high = s - 1

        while low <= high:
            mid = (low + high) // 2
            if (nums[mid] == target):
                return mid
            elif nums[mid] < target:
                low = mid + 1
            else:
                high = mid - 1
        return -1
        



"""

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int s = nums.size();
        int high = s - 1;
        while (low <= high) {
            int mid = (low + high)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }

        }
        return -1;
    }
};

"""