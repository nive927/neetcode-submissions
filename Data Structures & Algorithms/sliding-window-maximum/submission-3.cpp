class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> output(n-k+1);
        
        // track the leftmost - first eligible in the window
        int l = 0;
        // track the curr or the rightmost from nums
        int r = 0;

        // window reading - keep it in decreasing (similar to monotonic logic)
        // O(1) push_front & back, pop_front and back
        // only push in the back and pop in the front - queue
        deque<int> q; // tracks the indices of r

        // < - very important
        // we will check r+1 inside the loop
        while(r < n) {

            while(!q.empty() && nums[r] > nums[q.back()]) {
                q.pop_back();
            }

            q.push_back(r);

            if(l > q.front()) {
                q.pop_front();
            }

            if((r+1) >= k) {
                output[l] = nums[q.front()]; 
                l++;
            }

            r++;

        }

        return output;

    }
};
