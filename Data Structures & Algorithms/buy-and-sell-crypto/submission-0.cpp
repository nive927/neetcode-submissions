class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maxProfit = 0;
        
        int currProfit = 0; 
        int buyIndex = 0;

        for(int i=1; i<prices.size(); i++) {

            currProfit = prices[i] - prices[buyIndex];

            if (currProfit < 0) {
                buyIndex = i;
            }

            maxProfit = max(maxProfit, currProfit);

        }


        return maxProfit;

    }
};
