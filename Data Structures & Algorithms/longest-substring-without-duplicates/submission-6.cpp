class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int len = 0;
        int left = 0;
        set<int> window;

        for(int right=0; right<s.size(); right++) {

            // window breaks
            while(window.count(s[right])) {
                window.erase(s[left]);
                left++;
            }

            window.insert(s[right]);
            len = max(len, (int)window.size());

        }

        return len;
    }
};
