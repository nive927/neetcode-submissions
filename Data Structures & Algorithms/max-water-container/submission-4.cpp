class Solution {
public:
    int maxArea(vector<int>& heights) {

        /*
        CONSTRAINTS:
            input: arr of heights of the bars (int)
            output: max. amount of water between bars by choosing TWO bars(int)
        */

        /*
        LOGIC:
            goal: maximize the area (l * distance btw. bars)
            - init. res = INT_MIN
            - two pointers from front and end - keep decreasing distance to complete one traversal
                - H = min(h[l], h[r])
                - dist = r-l
                - area = l*dist
                - store in res = max(res, area)
                - if h[l] < h[r] l++ else r--
            - return res
        */

        int l = 0;
        int r = heights.size()-1;
        int res = INT_MIN;

        while (l < r) {

            int h = min(heights[l], heights[r]);
            int dist = r - l;
            int area = h * dist;

            res = max(res, area);

            if(heights[l] <= heights[r]) {
                l++;
            } else {
                r--;
            }

        }

        return res;


        /*
        COMPLEXITY:
            time: O(n) - one linear search
            space: O(1) - no extra space
        */


        
    }
};
