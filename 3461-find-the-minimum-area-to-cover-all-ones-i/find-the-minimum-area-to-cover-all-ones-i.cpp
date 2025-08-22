class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
         int ro = grid.size();
        if (ro == 0) return 0;
        int co = grid[0].size();
        
        int top = ro, bottom = -1, left = co, right = -1;
        for (int r = 0; r < ro; ++r) {
            for (int c = 0; c < co; ++c) {
                if (grid[r][c] == 1) {
                    top = min(top, r);
                    bottom = max(bottom, r);
                    left = min(left, c);
                    right = max(right, c);
                }
            }
        }
        
        return (right - left + 1) * (bottom - top + 1);
        
    }
};