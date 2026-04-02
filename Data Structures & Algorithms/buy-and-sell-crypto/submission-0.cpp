class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int min_price = prices[0];
        int max_profit = 0;

        for (int i = 1; i < prices.size(); ++i) {

            int current_profit = prices[i] - min_price;

            if (current_profit > max_profit) {
                max_profit = current_profit;
            }

            if (prices[i] < min_price) {
                min_price = prices[i];
            }

            // A more concise way to combine steps 2 and 3:
            // max_profit = std::max(max_profit, prices[i] - min_price);
            // min_price = std::min(min_price, prices[i]);
        }

        return max_profit;
    }
};