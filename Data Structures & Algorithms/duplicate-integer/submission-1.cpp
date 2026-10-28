class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> counter;
        for (int i=0; i<nums.size(); i++) {
            if(counter.find(nums[i]) != counter.end()) {
                return true;
            }
            counter.insert(nums[i]);
        }
        return false;
    }
};