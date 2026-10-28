class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int i=0;
        int j=1;

        while(i<nums.size() && j<nums.size()) {

            if(nums[i] == 0 && nums[j] !=0) {
                swap(nums[i], nums[j]);
            }

            if(nums[i] != 0) {
                i++;
            } // index for tracking 0 pos

          j++;

        }
        
    }
};