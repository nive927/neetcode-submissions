class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(edges.size() + 1, 0); // 1-based indexing

        // Build graph
        for (const auto& edge : edges) {
            int src = edge[0], dst = edge[1];
            adj[src].push_back(dst);
            adj[dst].push_back(src);
            indegree[src]++;
            indegree[dst]++;
        }

        // Prune all leaves using BFS
        queue<int> q;

        for (int i = 1; i <= edges.size(); ++i) {
            if (indegree[i] == 1) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front(); q.pop();
            indegree[node]--;

            for (int neighbor : adj[node]) {
                if (--indegree[neighbor] == 1) {
                    q.push(neighbor);
                }
            }
        }

        // Find last edge that connects two nodes still in cycle
        for (int i = edges.size() - 1; i >= 0; --i) {
            int u = edges[i][0], v = edges[i][1];
            if (indegree[u] > 0 && indegree[v] > 0) {
                return {u, v};
            }
        }

        return {};
    }
};
