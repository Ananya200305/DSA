class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP = INT_MAX;
        int maxProfit = 0;

        for(int i = 0 ; i < prices.size(); i++){
            if(prices[i] < minP){
                minP = prices[i];
            }else{
                maxProfit = max(maxProfit, prices[i] - minP);
            }
        }

        return maxProfit;
    }
};