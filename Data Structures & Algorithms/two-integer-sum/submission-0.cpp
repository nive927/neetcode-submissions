class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        map<int, int> cache;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++) {

            int required = target - nums[i];

            if (cache.count(required)) {

                ans.push_back(cache[required]);
                ans.push_back(i);
                break;
            }

            cache[nums[i]] = i;

        }

        return ans;
        
    }
};
