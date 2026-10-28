class Solution {
public:
    
    bool dfs(int index, int r, int c, vector<vector<char>>& board, vector<vector<bool>> visited, string word) {

        if (index == word.size()) {
            return true;
        }

        bool res;

        if(min(r, c) < 0 ||
                r >= board.size() || c >= board[0].size() ||
                visited[r][c] ||
                board[r][c] != word[index]) {
                    return false;
                }
        
        visited[r][c] = true;
        res =  dfs(index+1, r+1, c, board, visited, word) ||
                dfs(index+1, r-1, c, board, visited, word) ||
                dfs(index+1, r, c+1, board, visited, word) ||
                dfs(index+1, r, c-1, board, visited, word);
        visited[r][c] = false;

        return res;

    }
    
    
    bool exist(vector<vector<char>>& board, string word) {

        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for(int r=0; r<board.size(); r++) {
            for(int c=0; c<board[0].size(); c++) {

                if(dfs(0, r, c, board, visited, word)) {
                    return true;
                }

            }
        }

        return false;
        
    }


};
