class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, 
                            {0, 1}, {0, -1}};
    set<pair<int, int>> visited;
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int islands = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == '1' && !visited.count({r, c})) {
                    bfs(grid, r, c);
                    islands++;
                }
            }
        }

        return islands;
    }

    void bfs(vector<vector<char>>& grid, int r, int c) {
        queue<pair<int, int>> q;
        q.push({r, c});
        visited.insert({r, c});

        while (!q.empty()) {
            auto node = q.front();q.pop();
            int row = node.first, col = node.second;
            for (int i = 0; i < 4; i++) {
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];
                if (nr >= 0 && nc >= 0 && nr < grid.size() && 
                    nc < grid[0].size() && grid[nr][nc] == '1' && !visited.count({nr, nc})) {
                    q.push({nr, nc});
                    visited.insert({nr, nc});
                }
            }
        }
    }
};