using namespace std;
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int, int> car;
        stack<double> stk;
        for (int i = 0; i < position.size(); i++) {
            car[position[i]] = speed[i];
        }

        sort(position.rbegin(), position.rend());
        for (int i = 0; i < position.size(); i++) {
            int p = position[i];
            int s = car[p];
    
            double time = (double)(target - p) / s;
        
            if (stk.empty() || time > stk.top()) {
                stk.push(time);
            }
            
        }
        return stk.size();
        
    }
};
