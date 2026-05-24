class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int min_price = prices[0];
        int max_profit = 0;

        for (int i = 0; i < prices.size(); i++) {
            int current_profit = prices[i] - min_price;
            
            if (current_profit > max_profit) {
                max_profit = current_profit;
            }
           
            if (prices[i] < min_price) {
                min_price = prices[i];
            }
        }
        return max_profit;



        
        
    }
};
