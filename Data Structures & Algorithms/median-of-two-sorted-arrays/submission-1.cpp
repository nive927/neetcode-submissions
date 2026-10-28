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
            int mid1 = l + (r - l) / 2;
            int mid2 = half - mid1;

            int left1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
            int right1 = (mid1 < len1) ? nums1[mid1] : INT_MAX;
            int left2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
            int right2 = (mid2 < len2) ? nums2[mid2] : INT_MAX;

            // Correct condition
            if (left1 <= right2 && left2 <= right1) {
                if (total % 2 != 0) {
                    return max(left1, left2);
                }
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            } 
            else if (left1 > right2) {
                r = mid1 - 1;
            } 
            else {
                l = mid1 + 1;
            }
        }

        return -1;
    }
};
