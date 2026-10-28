class Solution {
public:
    int maxArea(vector<int>& heights) {

        int l = 0;
        int r = heights.size() - 1;
        int maxAmt = 0, currAmt, h, d;

        while (l<r) {

            h = (heights[l] <= heights[r]) ? heights[l] : heights[r];
            d = (r - l);

            currAmt = h*d;
            maxAmt = max(currAmt, maxAmt);

            if(heights[l] <= heights[r]) {
                l++;
            } else {
                r--;
            } 

        }

        return maxAmt;
        
    }
};
