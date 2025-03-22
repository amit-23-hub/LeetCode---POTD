class Solution {
public:
    bool bfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        int nodecnt = 0; 
        int edcnt = 0; 

        vis[node] = 1;  // Marking node as visited
        queue<int> q; 
        q.push(node); 

        while (!q.empty()) {
            int nd = q.front(); 
            q.pop();
            nodecnt++; 
            edcnt += adj[nd].size();  

            for (auto &it : adj[nd]) {
                if (!vis[it]) {
                    q.push(it);  
                    vis[it] = 1;  
                }
            }
        }

        return (edcnt / 2 == nodecnt * (nodecnt - 1) / 2);
    }

    int countCompleteComponents(int n, vector<vector<int>>& ed) {
        int m = ed.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < m; i++) {
            adj[ed[i][0]].push_back(ed[i][1]);  
            adj[ed[i][1]].push_back(ed[i][0]);  
        } 

        vector<int> vis(n, 0);  
        int cnt = 0;  
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt += bfs(i, adj, vis);  
            }
        }
        return cnt;  
    }
};
