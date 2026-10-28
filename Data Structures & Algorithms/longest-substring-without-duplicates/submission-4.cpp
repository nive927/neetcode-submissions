class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        set<char> seen;

        int l=0;
        int r=1;

        seen.insert(s[l]);

        int ans;

        if ((s.size() == 0) || (s.size() == 1)) { return s.size(); }
        

        while (r < s.size()) {

            while (seen.count(s[r])) {
                seen.erase(s[l]);
                l++;
            }

            seen.insert(s[r]);

            ans = max(ans, r - l + 1);

            r++;

        }

        return ans;

    }
};
