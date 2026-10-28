class Solution {
public:
    int findMin(vector<int> &nums) {

        int l = 0;
        int r = nums.size() - 1;
        int mid, res = nums[0];

        while(l<=r) {

            if(nums[l] < nums[r]) {
                res = min(res, nums[l]);
                break;
            }

            mid = r+(l-r)/2;

            if(nums[l] > nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }

            res = min(res, nums[mid]);
        }

        return res;
        
    }
};
