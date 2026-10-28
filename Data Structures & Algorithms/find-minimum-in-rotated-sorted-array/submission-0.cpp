class Solution {
public:
    int findMin(vector<int> &nums) {
        
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        int ans = nums[0];

        while (l <= r) {

            mid = l + (r-l) / 2;

            if(nums[mid] >= nums[r]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }

            ans = min(ans, nums[mid]);

        }

        return ans;
        

    }
};
