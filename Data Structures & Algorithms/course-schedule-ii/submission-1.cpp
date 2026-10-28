class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // topo sort result
            vector<int> topo;
            
            // build the adj list for repr. graph
            unordered_map<int, vector<int>> adj;
            for(auto pre: prerequisites) {
    
                int src = pre[1];
                int dst = pre[0];
    
                if(adj.find(src) == adj.end()) {
                    adj[src] = vector<int>(); // INIT STEP is super important
                }
    
                adj[src].push_back(dst);
            }
    
            // build the indegree counter
            vector<int> indegree(numCourses, 0);
            for(int i=0; i<numCourses; i++) {
                for(auto nei: adj[i]) {
                    indegree[nei]++;
                }
            }
    
            // push the nodes with indegree 0 as the starting point of BFS
            queue<int> q;
            for(int i=0; i<numCourses; i++) {
    
                if(indegree[i] == 0) {
                    q.push(i);
                }
    
            }
    
            // BFS - Kahn's algorithm to det. the ordering
            while(!q.empty()) {
    
                int top = q.front();
                q.pop();
    
                topo.push_back(top);
    
                for(auto nei: adj[top]) {
                    indegree[nei]--;
                    if(indegree[nei] == 0) {
                        q.push(nei);
                    }
                }
            }
    
            if (topo.size() == numCourses) {
                return topo;
            }

            topo.clear();
            return topo;
        
    }
};
