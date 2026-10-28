class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<pair<int, int>> stack; // (index, value)
        vector<int> result(temperatures.size(), 0);

        for(int i=0; i<temperatures.size(); i++) {

            if(i==0) {
                stack.push({i, temperatures[i]});
            }

            int currTemp = temperatures[i];

            while(!stack.empty() && stack.top().second < currTemp) {

                auto p = stack.top();
                stack.pop();
                result[p.first] = i - p.first; 

            }

            stack.push({i, temperatures[i]});

        }

        return result;
        
    }
};
