#include <queue>
#include <tuple>

class Solution {
public:
    int ROWS, COLS;

    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();
        
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (bfs(board, word, r, c)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool bfs(vector<vector<char>>& board, string& word, int sr, int sc) {
        if (board[sr][sc] != word[0]) return false;

        queue<tuple<int, int, int, vector<vector<bool>>>> q; 
        // (row, col, index in word, visited matrix)

        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        visited[sr][sc] = true;
        q.push({sr, sc, 1, visited});

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            auto [r, c, idx, vis] = q.front();
            q.pop();

            if (idx == word.size()) {
                return true;
            }

            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS &&
                    !vis[nr][nc] && board[nr][nc] == word[idx]) {

                    auto new_vis = vis;
                    new_vis[nr][nc] = true;
                    q.push({nr, nc, idx + 1, new_vis});
                }
            }
        }

        return false;
    }
};
