class Solution {
public:
    int characterReplacement(string s, int k) {

        int left = 0;
        int maxFreq = 0;
        int ans = 1;
        unordered_map<char, int> counter;

        for(int right=0; right<s.size(); right++) {

            // add right to window
            counter[s[right]]++;
            maxFreq = max(maxFreq, counter[s[right]]);

            // window break condition
            while((right-left+1)-maxFreq > k) {
                counter[s[left]]--;
                left++;
            }

            // update the ans
            ans = max(ans, right-left+1);

        }

        return ans;
        
    }
};
