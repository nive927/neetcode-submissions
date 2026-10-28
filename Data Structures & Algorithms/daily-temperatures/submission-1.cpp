class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        // monotonically decreasing
        // (index, temp)
        stack<pair<int, int>> s;
        vector<int> res(temperatures.size(), 0);

        for(int i=0; i<temperatures.size(); i++) {

            while(!s.empty() && s.top().second < temperatures[i]) {
                auto p = s.top();
                s.pop();
                res[p.first] = i - p.first;
            }

            s.push(make_pair(i, temperatures[i]));
        }


        return res;
        
    }
};
