class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> picked(nums.size(), false);
        backtrack(nums, current, picked, result);
        return result;
    }

private: 
    void backtrack(vector<int>& nums, vector<int>& current, 
               vector<bool>& picked, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (picked[i]) continue;
            picked[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, current, picked, result);
            picked[i] = false;
            current.pop_back();
        }
    }
};


/*

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;
        dfs(0,target, candidates, current, result);
        return result;
    }
private: 
    void dfs(int start, int target, vector<int>& candidates, vector<int>& current, 
            vector<vector<int>>& result) {
                if (target == 0) {
                    result.push_back(current);
                    return;
                }

                for (int i = start; i < candidates.size(); i++) {
                    if (i > start && candidates[i] == candidates[i - 1]) continue;

                    if (candidates[i] > target) break;

                    current.push_back(candidates[i]);

                    dfs(i + 1, target - candidates[i], candidates, current, result);
                    current.pop_back();
                }
            }
};

*/