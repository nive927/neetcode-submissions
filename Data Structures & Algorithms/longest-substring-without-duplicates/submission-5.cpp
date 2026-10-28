class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int ans = 0;
        int window = 0;
        int left = 0;

        // hash set to check for duplicates
        unordered_set<char> seen;

        for(int right=0; right<s.size(); right++) {

            // window break condition
            while(seen.count(s[right]) != 0) {
                seen.erase(s[left]);
                window--;
                left++;
            }

            // add arr[right] to window
            seen.insert(s[right]);
            window++;

            // update ans
            ans = max(window, ans);

        }


        return ans;

    }
};
