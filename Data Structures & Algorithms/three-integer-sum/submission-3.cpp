class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> res = {};        
        
        int target = 0;

        // sort asc
        sort(nums.begin(), nums.end());

        // one traversal through the entire list
        for(int i=0; i<nums.size(); i++) {

            // if the current item is the target
            // adding anything greater (all upcoming indices are greater because of the sort)
            // than it will
            // only increase the sum
            if (nums[i] > target) {
                break;
            }
            
            // distinct pairs
            if(nums[i] == nums[i-1] && i > 0) {
                continue;
            }

            int l = i+1;
            int r = nums.size() - 1;

            // find the remaining sum
            while(l < r) {

                int sum = nums[i] + nums[l] + nums[r];

                if(sum < target) {
                    l++;
                } else if (sum > target) {
                    r--;
                } else if (sum == target) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(nums[l] == nums[l - 1] && l <= r) {
                        l++;
                    }
                }

            }

        }

        return res;
        
    }
};
