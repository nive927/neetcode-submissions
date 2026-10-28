class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // Always binary search on smaller array
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        
        int len1 = nums1.size();
        int len2 = nums2.size();
        int total = len1 + len2;
        int half = (total + 1) / 2;

        int l = 0;
        int r = len1;

        while (l <= r) {
            int i = l + (r - l) / 2;
            int j = half - i;

            int left1 = (i > 0) ? nums1[i - 1] : INT_MIN;
            int right1 = (i < len1) ? nums1[i] : INT_MAX;
            int left2 = (j > 0) ? nums2[j - 1] : INT_MIN;
            int right2 = (j < len2) ? nums2[j] : INT_MAX;

            // Correct condition
            if (left1 <= right2 && left2 <= right1) {
                if (total % 2 != 0) {
                    return max(left1, left2);
                }
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            } 
            else if (left1 > right2) {
                r = i - 1;
            } 
            else {
                l = i + 1;
            }
        }

        return -1;
    }
};
