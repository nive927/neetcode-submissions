class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // vars
        vector<vector<int>> ans;
        int target = 0;
        
        // sort the nums list in asc. order
        sort(nums.begin(), nums.end());

        // traverse through every number
        for(int i=0; i<nums.size(); i++) {

            int l = i+1;
            int r = nums.size()-1;

            if(i>0 && (nums[i] == nums[i-1])) {
                continue;
            }

            while (l<r) {

                int curr = nums[i] + nums[l] + nums[r];

                if(curr == target) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    
                    while(l<r && (nums[l] == nums[l-1])) {
                        l++;
                    }


                } else if (curr > target) {
                    r--;
                } else {
                    l++;
                }

            }

        } 

        return ans;       


    }
};
