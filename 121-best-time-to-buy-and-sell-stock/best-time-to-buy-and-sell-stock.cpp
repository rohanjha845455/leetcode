class Solution {
public:
    int maxProfit(vector<int>& prices) { 
        int maxp = 0, bbuy = prices[0];
        for (int i = 1; i < prices.size(); i++) {  
            maxp = max(maxp, prices[i] - bbuy); 
            bbuy = min(bbuy, prices[i]);  
        }
        return maxp;  
    }
};
