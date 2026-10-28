class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0;
        int high = (m * n) - 1;

        int mid;
        int midElement;

        // DON'T FORGET THIS - helps save time
        // Not really necessary for correctness
        if (m == 0) { return false;}

        while (low <= high) {

            mid = low + (high-low) / 2;
            midElement = matrix[mid / n][mid % n]; // ONLY extra line

            if (midElement == target) { return true; }
            if (midElement < target) { low = mid + 1; }
            if (midElement > target) { high = mid - 1; }

        }

        return false;
        
    }
};
