class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mapper;
        vector<int> ans(2);

        for(int i=0; i<nums.size(); i++) {
            if(mapper.find(nums[i]) != mapper.end()) {
                ans = {mapper[nums[i]], i};
                return ans;
            }

            mapper[target - nums[i]] = i;

        }
        
    }
};
