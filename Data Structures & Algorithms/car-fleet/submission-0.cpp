class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int, int>> cars; // typo: 'pairt' -> 'pair'

        // combine into one tracker var
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        // sort by position descending (farthest cars first)
        sort(cars.rbegin(), cars.rend());
        
        stack<double> s;

        for (auto car : cars) {
            double currTime = (double)(target - car.first) / car.second;
            // FIX: stack is LIFO so use s.top(), not s.front()
            if (!s.empty() && currTime <= s.top()) {
                // do NOT push if this car joins the fleet ahead
                continue;
            }
            s.push(currTime); // start a new fleet
        }

        return s.size();
    }
};
