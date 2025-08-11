class Solution {
public:
    int prims(int V , vector<vector<pair<int,int>>>& adj) {

        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> minH; 
        vector<int> isMST(V, 0); 

        minH.push({0,{0,-1}}); 
        int cost = 0; 

        while (!minH.empty()) {
            int wt = minH.top().first; 
            int node = minH.top().second.first; 
            minH.pop(); 

            if (!isMST[node]) {
                cost += wt; 
                isMST[node] = 1; 

                for (int i = 0; i < adj[node].size(); i++) {
                    if (!isMST[adj[node][i].first]) {
                        minH.push({adj[node][i].second, {adj[node][i].first, node}});
                    }
                }
            }
        }
        return cost;  
    }  

    int minCostConnectPoints(vector<vector<int>>& pt) {
        int n = pt.size(); 
        vector<vector<pair<int,int>>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = pt[i][0]; 
                int y1 = pt[i][1]; 
                int x2 = pt[j][0];
                int y2 = pt[j][1]; 
                int dis = abs(x1 - x2) + abs(y1 - y2); 
                adj[i].push_back({j, dis}); 
                adj[j].push_back({i, dis}); 
            }
        } 
        return prims(n, adj); 
    }
};
