class Solution {
    public int maxProfit(int[] prices) {
        int profit = 0;
        int currStock = prices[0];
        for(int i=1;i<prices.length;i++) {
            profit = Math.max(profit,prices[i]-currStock);
            if(currStock > prices[i])  {
                currStock = prices[i];
            }
        }

        return profit;
    }
}