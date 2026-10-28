class Solution {
public:

    void helper(vector<int> currset, vector<int> nums, vector<vector<int>> &subsets, int start) {

        // modify the answer
        subsets.push_back(currset);

        for(int i=start; i<nums.size(); i++) {

            // include the number
            currset.push_back(nums[i]);
            helper(currset, nums, subsets, i+1);
            // exclude the number
            currset.pop_back();

        }

    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> subsets;
        vector<int> currset;

        helper(currset, nums, subsets, 0);

        return subsets;
        
    }
};
