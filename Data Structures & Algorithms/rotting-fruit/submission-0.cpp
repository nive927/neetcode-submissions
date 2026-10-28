class Solution {
public:

    vector<pair<int, int>> directions = {{0, 1}, // r
                                         {-1, 0}, // u
                                         {1, 0}, // d
                                         {0, -1}}; // l

    int orangesRotting(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        int fresh = 0;
        int time = 0;

        queue<pair<int, int>> q;

        for(int r=0; r<rows; r++) {
            for(int c=0; c<cols; c++) {

                if(grid[r][c] == 1) {
                    fresh++;
                } else if(grid[r][c] == 2) {
                    q.push({r, c});
                }
            }
        }

        while(fresh > 0 && !q.empty()) {

            int ws = q.size();

            for(int i=0; i<ws; i++) {
                auto p = q.front();
                int r = p.first;
                int c = p.second;
                q.pop();

                for(auto d: directions) {

                    int newR = r + d.first;
                    int newC = c + d.second;

                    if(newR >= 0 && newC >= 0 && newR < rows && newC < cols && grid[newR][newC] == 1) {

                        grid[newR][newC] = 2;
                        q.push({newR, newC});
                        fresh--;
                    }

                }
            }

            time++;

        }

        return (fresh == 0) ? time : -1;
         
    }
};
