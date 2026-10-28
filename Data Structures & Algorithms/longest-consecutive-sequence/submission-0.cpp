class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int ans = 0;

        unordered_set<int> set(nums.begin(), nums.end()); // NOTE

        for(auto num: set) {

            // check if it is the start of the sequence
            if(set.find(num - 1) == set.end()) {

                int length = 1;

                while(set.find(num + length) != set.end()) {
                    length++;
                }

                ans = max(length, ans);

            }

        }

        return ans;


        
    }
};
