class Solution {
public:
    vector<int> topologicalSort(int n, vector<vector<int>>& edges) {
    
        // vars
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);
        vector<int> topo;

        // build adj list for g
        for(auto edge: edges) {
            // u -> v
            adj[edge[0]].push_back(edge[1]);
        }

        // build the indegree counter
        for(int i=0; i<n; i++) {
            for(auto nei: adj[i]) {
                indegree[nei]++;
            }
        }

        // Kahn's algo: Topo BFS
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {

            auto node = q.front();
            q.pop();

            // add to topo order
            topo.push_back(node);

            for(auto nei: adj[node]) {
                if(--indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        if (topo.size() != n)
            topo.clear();

        return topo;

    }
};
