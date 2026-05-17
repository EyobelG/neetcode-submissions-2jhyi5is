class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int current_area = 0;
        int max_area = 0;
        while (left < right) {
            current_area = (right - left) * min(heights[left], heights[right]);
            max_area = max(max_area, current_area);
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
};