class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Build adjacency list
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& time : times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adj[u].push_back({v, w});
        }

        // Step 2: Initialize distances and visited array
        vector<int> dist(n + 1, INT_MAX);
        vector<bool> explore(n + 1, false);
        dist[k] = 0;  // Distance of source to itself is 0

        //Dijkstra's algorithm 
        for (int cnt = 1; cnt <= n; cnt++) { ///   n  is number of vertices 
        // hme sbse minum ko selct krna hota hai 
            int node = -1;    //  kyuki negative node nhi hai to hm isse compare kr skte hai  aur uski val int max mle lenege 
            int value = INT_MAX;

            for (int i = 1; i <= n; i++) {
                if (!explore[i] && dist[i] < value) {
                    node = i;
                    value = dist[i];
                }
            }

            if (node == -1) break; // No unvisited reachable node

            explore[node] = true; /// visit krne k badd explore me true kr deneg 

            for (int j = 0 ; j<adj[node].size() ; j++) {
                int neighbour = adj[node][j].first;   
                int weight = adj[node][j].second;     
                if (!explore[neighbour] && dist[node] + weight < dist[neighbour]) {
                    dist[neighbour] = dist[node] + weight;
                }
            }
        }

        // Compute max distance
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
