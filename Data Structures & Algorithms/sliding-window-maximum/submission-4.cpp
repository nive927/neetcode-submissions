class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;
        vector<int> res;
        deque<int> q; // stores indices, not values

        for (int right = 0; right < nums.size(); ++right) {
            
            // Remove all elements smaller than nums[right]
            while (!q.empty() && nums[right] > nums[q.back()]) {
                q.pop_back();
            }

            // Add current right to the window
            q.push_back(right);

            // Remove the front if it's out of the window
            if (q.front() < right - k + 1) {
                q.pop_front();
            }

            // Start recording results only when the window is size k
            // example: only after index 3 if k=3
            if (right + 1 >= k) {
                res.push_back(nums[q.front()]); // q.front() is the index of max in window
            }
        }

        return res;
    }
};
