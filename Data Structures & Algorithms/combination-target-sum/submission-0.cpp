class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, target, 0, 0, current, result);
        return result;
    
    }
private:
    void backtrack(vector<int>& nums, int target, int start, int sum,
    vector<int>& current, vector<vector<int>>& result ) {
        if (sum == target) {
            result.push_back(current);
            return;
        }

        if (sum > target){
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);
            backtrack(nums, target, i, sum + nums[i], current, result);
            current.pop_back();
        }

    }
};
