class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int ans = INT_MIN;

        for(int right=0; right<prices.size(); right++) {

            // window break condition
            if(prices[right] < prices[left]) {
                left = right;
            }

            // add right
            int currProfit = prices[right] - prices[left];
            ans = max(ans, currProfit);

        }


        return (ans == INT_MIN) ? 0 : ans;
    }
};
