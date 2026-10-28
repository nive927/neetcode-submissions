class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        // you need to reverse the matrix col by col
        // this is not a sort operation
        reverse(matrix.begin(), matrix.end());

        // IN-PLACE transpose
        for(int r=0; r<matrix.size(); r++) {
            // The inner loop (c) iterates over the columns,
            // but only for elements above the diagonal (c = r+1 to n-1).
            for(int c=r+1; c<matrix[r].size(); c++) {
                swap(matrix[r][c], matrix[c][r]);
            }
        }
        
    }
};
