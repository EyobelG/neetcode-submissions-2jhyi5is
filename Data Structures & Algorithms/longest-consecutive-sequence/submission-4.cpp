class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet;
        for (int num: nums) {
            hashSet.insert(num);
        }

        int result = 0;
        for (int num: hashSet) {
            if (not hashSet.contains(num - 1)) {
                int next = num;

                while (hashSet.contains(next)) {
                    next++;
                }

                result = std::max(result, next - num);
            }
        }
        return result;
        
    }    
};
