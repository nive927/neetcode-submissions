class Solution {
public:

    void helper(vector<bool> pick, vector<int> curr, vector<int> nums, vector<vector<int>> &permutations) {

        // base case - modify the answer
        if(curr.size() == nums.size()) {
            permutations.push_back(curr);
            return;
        }

        for(int i=0; i<nums.size(); i++) {

            // modify state
            if(!pick[i]) {
                curr.push_back(nums[i]);
                
                pick[i] = true;
                
                helper(pick, curr, nums, permutations);

                curr.pop_back();

                pick[i] = false;
            }
        }


    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> permutations;
        vector<int> curr;
        vector<bool> picked(nums.size(), false);


        helper(picked, curr, nums, permutations);

        return permutations;
        
    }
};
