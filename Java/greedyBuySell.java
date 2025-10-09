public class greedyBuySell {
    static int maxProfit(int prices[], int n) {
        int minSoFar=prices[0];
        int max_Profit = 0;
        for(int i=1; i<n; i++) {
            minSoFar = Math.min(minSoFar, prices[i]);
            int profit = prices[i] - minSoFar;
            max_Profit = Math.max(max_Profit, profit);
        }
        return max_Profit;
    }
    public static void main(String args[]) {
        int prices[] = {7, 1, 5, 3, 6, 4};
        int n = prices.length;
        int max_profit = maxProfit(prices, n);
        System.out.println(max_profit);
    }
}
