class Solution {
public:

    vector<vector<string>> res;

    bool check(string s, int l, int r) {
        for(int i=l, j=r; i<j; i++, j--) {
            if(s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    void backtrack(int l, vector<string>& curr, string& s) {

        if(l == s.size()) {
            res.push_back(curr);
            return;
        }

        for(int i=l; i<s.size(); i++) {
            if(check(s, l, i)) {
                curr.push_back(s.substr(l, i - l + 1));
                backtrack(i+1, curr, s);
                curr.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {

        res.clear();

        int l = 0;
        vector<string> curr;

        backtrack(l, curr, s);
        
        return res;
    }
};
