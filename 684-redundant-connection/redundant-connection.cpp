class Solution {
public:

     bool bfs(int src, vector<int> adj[], int n) {
        vector<bool> vis(n + 1, false);    // for making node visited 

        queue<pair<int,int>>q ; 
        q.push({src,-1}) ; 
         vis[src] = true;// is node ko visit kr liye 

         while(!q.empty()){
            int node = q.front().first ; 
            int parent = q.front().second;
            q.pop();

            for(int neighbour : adj[node]){
                if(!vis[neighbour]){
                    vis[neighbour] = true  ; 
                     q.push({neighbour, node});
                } else if (neighbour != parent) {
                    return true; // cycle detected
                }
            }
         }
         return false  ; 
     }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size() ; 
        int m = edges[0].size() ; 

         vector<int> adj[n + 1];
        for(int i = 0 ; i< n ; i++){
            int u = edges[i][0] ; 
            int v = edges[i][1] ;
            adj[u].push_back(v) ; 
            adj[v].push_back(u) ; 

            if (bfs(u, adj, n)) {
                return edges[i];
            }
        }

        
 return {}; 
    }
};