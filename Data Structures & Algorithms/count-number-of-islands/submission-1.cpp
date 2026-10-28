class Solution {
public:

    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

    void bfs(int row, int col, vector<vector<char>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;
        set<pair<int, int>> visited;

        q.push({row, col});

        while(!q.empty()) {

            auto top = q.front();
            int r = top.first;
            int c = top.second;
            q.pop();
            visited.insert({r, c});

            for(auto p: directions) {
                int newR = r + p.first;
                int newC = c + p.second;

                if(newR >= 0 && newC >= 0 && newR < rows && newC < cols && grid[newR][newC] == '1') {
                    if(!visited.count({newR, newC})) {
                        q.push({newR, newC});
                        grid[newR][newC] = '0';
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int islands = 0;

        int rows = grid.size();
        int cols = grid[0].size();

        // you need to run bfs for every '1' cell to check for islands
        for(int r=0; r<rows; r++) {
            for(int c=0; c<cols; c++) {

                if(grid[r][c] == '1') {
                    bfs(r, c, grid);
                    islands++; // only works if you setting all the other neighbors to 0
                }

            }
        }

        return islands;
        
    }
};
