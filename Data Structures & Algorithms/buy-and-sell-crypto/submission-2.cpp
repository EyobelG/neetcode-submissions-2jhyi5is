class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int min_price = prices[0];
        int max_profit = 0;

        for (int i = 0; i < prices.size(); i++) {
            min_price = min(min_price, prices[i]);

            max_profit = max(max_profit, prices[i] - min_price);

            if (max_profit < 0) {
                return 0;
            }
        }
        return max_profit;



        
        
    }
};
