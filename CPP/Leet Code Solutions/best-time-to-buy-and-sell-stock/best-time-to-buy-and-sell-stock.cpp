class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int max_profit = 0;
        for(int i=1;i<prices.size();i++){
            min_price = min(min_price,prices[i]);
            int profit = prices[i] - min_price;
            max_profit = max(max_profit,profit);
        }
        return max_profit;
    }
};