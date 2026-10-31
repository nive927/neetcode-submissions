class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int ans = 0;

        for(auto n: nums) { // alternative: find the total sum and subtract each num
            ans ^= n;
        }

        return ans;
        
    }
};
