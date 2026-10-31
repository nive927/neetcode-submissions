class Solution {
public:
    string makeGood(string s) {

        string stk = "";

        for(auto c: s) {
            
            if(stk.size() != 0 && abs(int(stk.back()) - int(c)) == 32) {
                    stk.pop_back();
            } else {
                stk.push_back(c);
            }
        }

        return stk;

    }
};
