class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minB = prices[0];
        int maxP = 0;

        for(int i = 1; i < prices.size(); i++){
            maxP = max(maxP, prices[i] - minB);
            minB = min(prices[i], minB);
        }
            
        return maxP;
    }
};
