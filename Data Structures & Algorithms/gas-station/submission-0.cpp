class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int tank = 0;
        int start = 0;
        int n = gas.size();

        for (int i = 0; i < n; i++) {
            int diff = gas[i] - cost[i];
            tank += diff;
            total += diff;
            if (tank < 0){
                start = i + 1;
                tank = 0;
            }
        }
        if (total >= 0) {
            return start;
        } else {
            return -1;
        }
        
    }
};
