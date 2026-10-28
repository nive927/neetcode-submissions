class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Step 1: Build the adjacency list
        unordered_map<int, vector<pair<int, int>>> adj;
        for (const auto& time : times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adj[u].push_back({v, w});
        }

        // Step 2: MinHeap to pick the shortest path next
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, k}); // {distance, node}

        // Step 3: Map to store the shortest distance to each node
        unordered_map<int, int> shortest;

        // Step 4: Standard Dijkstra
        while (!minHeap.empty()) {
            auto [currTime, currNode] = minHeap.top();
            minHeap.pop();

            // If we already finalized this node, skip
            if (shortest.find(currNode) != shortest.end()) {
                continue;
            }

            // Finalize the shortest distance
            shortest[currNode] = currTime;

            // Explore neighbors
            for (auto [neiNode, neiTime] : adj[currNode]) {
                if (shortest.find(neiNode) == shortest.end()) {
                    minHeap.push({currTime + neiTime, neiNode});
                }
            }
        }

        // Step 5: Check if all nodes are reachable
        if (shortest.size() != n) {
            return -1;
        }

        // Step 6: The answer is the maximum delay time among all reachable nodes
        int ans = 0;
        for (const auto& [node, time] : shortest) {
            ans = max(ans, time);
        }
        return ans;
    }
};
