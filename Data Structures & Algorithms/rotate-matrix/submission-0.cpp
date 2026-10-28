class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        reverse(matrix.begin(), matrix.end());

        for(int r=0; r<matrix.size(); r++) {
            for(int c=r+1; c<matrix[r].size(); c++) {
                swap(matrix[r][c], matrix[c][r]);
            }
        }
        
    }
};
