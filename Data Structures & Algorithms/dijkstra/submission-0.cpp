class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        
        // vars
        // src -> [{dest1, weight1}, {dest2, weight2}, ...]
        unordered_map<int, vector<pair<int, int>>> adj;

        // init the graph: adj list
        // n: vertex nodes numbered from 0 to n-1
        for(int i=0; i<n; i++) {
            adj[i] = vector<pair<int,int>>(); // init
        }

        // build the graph: adj list
        for(auto edge: edges) {

            auto s = edge[0];
            auto d = edge[1];
            auto w = edge[2];

            adj[s].push_back({d, w});
        }

        // Dijkstra's Shortest Path Algo
        // store pair: {path cost to node from start, node}
        // use minHeap for shortest path cost
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> minHeap;
        // to track the shortest path cost to node while performing Dijkstra's BFS
        unordered_map<int, int> shortest; // {cost (accumulative), node}

        // start
        minHeap.push({0, src});

        // run algo till minHeap is not empty (skips nodes if already seen)
        while(!minHeap.empty()) {

            auto p = minHeap.top();
            auto currCost = p.first;
            auto currNode = p.second;
            minHeap.pop();

            // If the shortest path has already been populated
            // Do nothing, just move onto the next pop
            // If the algo is done, this just ensures that everything
            // gets popped out
            if(shortest.find(currNode) != shortest.end()) {
                continue;
            }

            // update the shortest path cost to the node
            shortest[currNode] = currCost;

            // push neighbors of currNode
            for(auto nei: adj[currNode]) {

                auto neiNode = nei.first;
                auto neiWeight = nei.second;

                if(shortest.find(neiNode) == shortest.end()) {

                    minHeap.push({currCost+neiWeight, neiNode});

                }

            }

        }

        // Fill in missing nodes
        // These did not have a path from the src
        for (int i = 0; i < n; i++) {
            if (shortest.find(i) == shortest.end()) {
                shortest[i] = -1;
            }
        }

        return shortest;

    }
};
