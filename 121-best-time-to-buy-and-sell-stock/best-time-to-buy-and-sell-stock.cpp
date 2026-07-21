class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = prices[0];
        int maxProfit = 0;

        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < minprice){
                minprice = prices[i];
            }else{
                maxProfit = max(maxProfit, prices[i]-minprice);
            }
        }

        return maxProfit;
    }
};