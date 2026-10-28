class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {

        for(int i=0, j=1; j<nums.size(); i++, j++) {
            if(nums[i] == nums[j]) {
                nums[i] *= 2;
                nums[j] = 0;
            }
        }

        int slow = 0; // tracks 0
        for(int fast=0; fast<nums.size(); fast++) {
            if(nums[slow] != 0) {
                slow++;
            } else if (nums[fast] !=0 ) {
                swap(nums[slow], nums[fast]);
                slow++;
            }
        }

        return nums;

    }
};
