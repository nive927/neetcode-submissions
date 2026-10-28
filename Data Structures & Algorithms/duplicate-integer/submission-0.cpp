class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        unordered_set<int> cache;

        for(int i=0; i<nums.size(); i++) {
            if (cache.count(nums[i])) return true;

            cache.insert(nums[i]);
        }
        return false;
    }
};
