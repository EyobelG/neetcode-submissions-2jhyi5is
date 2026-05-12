class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array (fewer binary search iterations)
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int totalLeft = (m + n + 1) >> 1;  // bit shift instead of division
        
        int low = 0, high = m;
        
        while (low <= high) {
            int i = (low + high) >> 1;  // bit shift
            int j = totalLeft - i;
            
            // Use ternary with constants for better branch prediction
            int maxLeftX = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRightX = (i == m) ? INT_MAX : nums1[i];
            int maxLeftY = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRightY = (j == n) ? INT_MAX : nums2[j];
            
            // Found correct partition
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // Odd total length
                if ((m + n) & 1) {  // bitwise AND instead of modulo
                    return max(maxLeftX, maxLeftY);
                }
                // Even total length
                return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) * 0.5;
            }
            
            // Adjust binary search bounds
            if (maxLeftX > minRightY) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }
        
        return 0.0;
    }
};