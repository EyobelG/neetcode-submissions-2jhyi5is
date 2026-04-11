class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        sort(nums.begin(), nums.end());
        dfs(0, result, current, nums);
        return result;
    }
private:
    void dfs(int start, vector<vector<int>>& result, vector<int>& current, vector<int>& nums) {
        result.push_back(current);


        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            current.push_back(nums[i]);
            dfs(i + 1, result, current, nums);
            current.pop_back();
            
        }
        
    }
};


