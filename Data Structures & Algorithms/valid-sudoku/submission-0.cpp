class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // NOTE: REDO the problem using bit masking after completing Bit Manip modules


        unordered_map<int, unordered_set<char>> rows, cols;
        map<pair<int, int>, unordered_set<char>> squares;

        int r = board.size();
        int c = board[0].size();

        for(int i=0; i<r; i++) {

            for(int j=0; j<c; j++) {

                if(rows[i].count(board[i][j]) ||
                    cols[j].count(board[i][j]) ||
                    squares[{i/3, j/3}].count(board[i][j])) {
                        return false;
                    }

                if(board[i][j] != '.') {
                    rows[i].insert(board[i][j]);
                    cols[j].insert(board[i][j]);
                    squares[{i/3, j/3}].insert(board[i][j]);
                }
                
            }

        }


        return true;

        
    }
};
