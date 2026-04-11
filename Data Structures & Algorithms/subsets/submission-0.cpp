class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        dfs(0, result, current, nums);
        return result;
    }
private: 
    void dfs(int index, vector<vector<int>>& result, vector<int>& current, vector<int>& nums) {
        
        if (index >= nums.size()){
            result.push_back(current);
            return;
        }
        current.push_back(nums[index]);
        dfs(index + 1, result, current, nums);

        current.pop_back();
        dfs(index + 1, result, current, nums);

    }
};

/*

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
    vector<int>& current, vector<vector<int>>& result) {
        if (sum == target) {
            result.push_back(current);
            return;
        }

        if (sum > target) {
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);
            backtrack(nums, target, i, sum + nums[i], current, result);
            current.pop_back();
        } 

    }
};

*/
