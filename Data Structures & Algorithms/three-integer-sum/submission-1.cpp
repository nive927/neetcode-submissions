class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // learn the hash map method as well
        // sorting method reduces the space complexity 

        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        int target = 0;

        for (int i = 0; i < nums.size(); i++) {
            
            if (nums[i] > target) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1, r = nums.size() - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum > target) {
                    r--;
                } else if (sum < target) {
                    l++;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;

                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
            }
        }
        return res;
        
        
    }
};
