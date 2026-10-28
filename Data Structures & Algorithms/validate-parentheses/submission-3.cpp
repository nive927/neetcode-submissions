class Solution {
public:
    bool isValid(string s) {

        stack<char> stk;
        unordered_map<char, char> mp;
        mp.insert({'}', '{'});
        mp.insert({')', '('});
        mp.insert({']', '['});

        if (s.size() == 0) {
            return true;
        }

        for(int i=0; i<s.length(); i++) {
            if(mp.find(s[i]) != mp.end() && stk.size() > 0) {
                char top = stk.top();
                stk.pop();
                
                if (top != mp[s[i]]) {
                    return false;
                }
            } else {
                stk.push(s[i]);
            }
        }

        if(stk.size() == 0) {
            return true;
        }

        return false;
        
    }
};
