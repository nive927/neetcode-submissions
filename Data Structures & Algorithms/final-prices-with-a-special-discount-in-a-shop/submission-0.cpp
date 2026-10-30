class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {

        stack<int> s;

        for(int i=0; i<prices.size(); i++) {
            while(!s.empty() && prices[s.top()] >= prices[i]) {
                int index = s.top();
                s.pop();
                prices[index] -= prices[i];
            }
        
            s.push(i); // track the indices to discount.
        }

        return prices;

    }
};
