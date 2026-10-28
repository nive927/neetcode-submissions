class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq;
        vector<int> ans(nums.size()-k+1);

        int l = 0;
        int r = 0;

        while(r < nums.size()) {

            // remove all items in the dq if they are less than the curr
            while(!dq.empty() && nums[r] > nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(r);

            if(l > dq.front()) {
                dq.pop_front();
            }

            if((r+1) >= k) {
                ans[l] = nums[dq.front()];
                l++;
            }

            r++;

        }

        return ans;
        
    }
};
