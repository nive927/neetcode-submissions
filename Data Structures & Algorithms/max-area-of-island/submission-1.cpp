class Solution {
public:

    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int bfs(int r, int c, vector<vector<int>>& grid) {

        queue<pair<int, int>> q;
        int area = 1;

        int rows = grid.size();
        int cols = grid[0].size();

        q.push({r, c});
        grid[r][c] = 0; // important

        while(!q.empty()) {

            int ws = q.size();
            for(int i=0; i<ws; i++) {

                auto p = q.front();
                q.pop();
                int row = p.first;
                int col = p.second;

                for(auto d: directions) {

                    int newR = row + d.first;
                    int newC = col + d.second;

                    if(newR >=0 && newC >= 0 && newR < rows && newC < cols && grid[newR][newC] == 1) {
                        grid[newR][newC] = 0;
                        q.push({newR, newC});
                        area++;
                    }

                }

            }

        }

        return area;

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;

        for(int r=0; r<rows; r++) {
            for(int c=0; c<cols; c++) {

                if(grid[r][c] == 1) {
                    maxArea = max(maxArea, bfs(r, c, grid));
                }

            }
        }

        return maxArea;
        
    }
};
