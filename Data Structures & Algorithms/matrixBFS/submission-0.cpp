class Solution {
public:
    vector<pair<int, int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };

    int shortestPath(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (grid[0][0] == 1 || grid[rows - 1][cols - 1] == 1)
            return -1;

        queue<pair<int, int>> q;
        set<pair<int, int>> visited;

        // start
        q.push({0, 0});
        visited.insert({0, 0});

        int steps = 0;

        while (!q.empty()) {
            int layerSize = q.size();

            for (int i = 0; i < layerSize; i++) {
                
                auto current = q.front();
                q.pop();

                int r = current.first;
                int c = current.second;

                if (r == rows - 1 && c == cols - 1)
                    return steps;

                for (auto dir : directions) {
                    int newR = r + dir.first;
                    int newC = c + dir.second;

                    if (newR >= 0 && newC >= 0 && newR < rows && newC < cols &&
                        grid[newR][newC] == 0 && visited.find({newR, newC}) == visited.end()) {
                        q.push({newR, newC});
                        visited.insert({newR, newC});
                    }
                }
            }

            steps++;
        }

        return -1; // No path found
    }
};