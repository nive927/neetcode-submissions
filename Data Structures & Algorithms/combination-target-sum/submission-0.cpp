class Solution {
public:

    vector<vector<int>> ans;

    void backtrack(int start, int total, vector<int> curr, vector<int> nums, int target) {

        if(total == target) {
            ans.push_back(curr);
            return;
        }

        for(int i=start; i<nums.size(); i++) {

            total += nums[i];
            if(total > target) {
                return;
            }

            curr.push_back(nums[i]);
            backtrack(i, total, curr, nums, target);
            total -= nums[i];
            curr.pop_back();

        }

    }


    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<int> curr;

        sort(nums.begin(), nums.end());
        backtrack(0, 0, curr, nums, target);

        return ans;       
        
    }
};
