class Solution {
public:
    int maxProfit(vector<int>& prices) {  // Rename function to 'maxProfit'
        int maxp = 0, bbuy = prices[0];  // Correct variable name: prices[0]
        
        for (int i = 1; i < prices.size(); i++) {  // Correct syntax in for loop
            if (prices[i] > bbuy) {
                maxp = max(maxp, prices[i] - bbuy);  // Corrected max function 
            }
            bbuy = min(bbuy, prices[i]);  // Update bbuy with the minimum price
        }
        return maxp;  // Return the maximum profit
    }
};
