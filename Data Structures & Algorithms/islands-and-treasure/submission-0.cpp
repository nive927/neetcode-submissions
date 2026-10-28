class Solution {
public:

    vector<pair<int, int>> directions = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };
    void islandsAndTreasure(vector<vector<int>>& grid) {

        // bfs vars
        queue<pair<int,int>> q;
        set<pair<int, int>> visited;

        // add all the sources to run bfs at the same time from
        // all the sources simultaneously
        for(int r=0; r<grid.size(); r++) {
            for(int c=0; c<grid[0].size(); c++) {
                if(grid[r][c] == 0) {
                    q.push({r, c});
                    visited.insert({r,c});
                }
            }
        }

        while(!q.empty()) {

            auto p = q.front();
            q.pop();
            auto r = p.first;
            auto c = p.second;

            for(auto dir: directions) {
                auto newR = r+dir.first;
                auto newC = c+dir.second;

                if(newR < grid.size() && newC < grid[0].size()
                && newR >=0 && newC>= 0 &&
                grid[newR][newC] == INT_MAX && !visited.count({newR, newC})) {
                    grid[newR][newC] = grid[r][c] + 1;
                    q.push({newR, newC});
                    visited.insert({newR, newC});
                }
            }

        }
        
    }
};
