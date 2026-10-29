class Solution {
public:
    int calPoints(vector<string>& operations) {

        stack<int> s;

        for(auto op: operations) {

            if (op == "+" && s.size() >=2) {
                int right = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                s.push(left);
                s.push(right);
                s.push(left+right);
            } else if(op == "D" && !s.empty()) {
                int top = s.top();
                s.pop();
                s.push(top);
                s.push(top*2);
            } else if (op == "C" && !s.empty()) {
                s.pop();
            } else {
                s.push(stoi(op)); // integer
            }
        }

        int ans = 0;
        while(!s.empty()) {
            ans += s.top();
            s.pop();
        }

        return ans;
        
    }
};