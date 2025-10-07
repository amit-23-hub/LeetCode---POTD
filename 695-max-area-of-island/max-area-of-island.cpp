class Solution {
public:
    int r ;
    int c ; 
    int row[4] = {1,-1,0,0} ; 
    int  col[4] = {0,0,-1,1} ; 
  bool valid(int  i ,  int  j ){
           return i>=0&&i<r&&j>=0&&j<c ; 
    }

    int maxAreaOfIsland(vector<vector<int>>& g) {
        
    r = g.size();
        c = g[0].size();

        int mx = 0; // maximum area
        queue<pair<int, int>> q;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (g[i][j] == 1) {
                    int cnt = 0;
                    q.push({i, j});
                    g[i][j] = 0; // mark visited

                    while (!q.empty()) {
                        auto [ni, nj] = q.front();
                        q.pop();
                        cnt++;

                        for (int k = 0; k < 4; k++) {
                            int x = ni + row[k];
                            int y = nj + col[k];

                            if (valid(x, y) && g[x][y] == 1) {
                                g[x][y] = 0; // mark visited
                                q.push({x, y});
                            }
                        }
                    }

                    mx = max(mx, cnt); // update max area
                }
            }
        }
        return mx;
    }
};