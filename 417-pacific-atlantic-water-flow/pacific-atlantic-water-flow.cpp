class Solution {
public:
    vector<int> dr = {0, 1, 0, -1}; // row directions
    vector<int> dc = {1, 0, -1, 0}; // column directions

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> atl(row, vector<bool>(col, false));
        vector<vector<bool>> pac(row, vector<bool>(col, false));
        
        queue<pair<int, int>> atlanticq;
        queue<pair<int, int>> pacificq;

        for (int c = 0; c < col; c++) {
            pacificq.push({0, c});
            pac[0][c] = true;
            atlanticq.push({row - 1, c});
            atl[row - 1][c] = true;
        }

        for (int r = 0; r < row; r++) {
            pacificq.push({r, 0});
            pac[r][0] = true;
            atlanticq.push({r, col - 1});
            atl[r][col - 1] = true;
        }

        bfs(pacificq, pac, grid);
        bfs(atlanticq, atl, grid);

        vector<vector<int>> res;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (atl[i][j] && pac[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }

    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& ocean, vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (int k = 0; k < 4; ++k) {
                int r = i + dr[k];
                int c = j + dc[k];

                if (r >= 0 && c >= 0 && r < row && c < col &&
                    !ocean[r][c] && grid[r][c] >= grid[i][j]) {
                    q.push({r, c});
                    ocean[r][c] = true;
                }
            }
        }
    }
};
