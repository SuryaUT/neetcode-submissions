class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minB = prices[0];
        int buy = prices[0];
        int maxP = 0;

        for(int i = 1; i < prices.size(); i++){
            if(prices[i] - minB > maxP){
                maxP = prices[i] - minB;
                buy = minB;
            }
            minB = min(prices[i], minB);
        }
            
        return max(0,maxP);
    }
};
