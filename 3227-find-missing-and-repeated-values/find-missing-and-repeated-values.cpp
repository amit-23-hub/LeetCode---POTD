class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> h(n * n + 1, 0);  
        int sum = 0, dup = -1;

        // Count frequency and calculate sum
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = g[i][j];
                h[val]++;
                sum += val;
                if (h[val] > 1) dup = val;
            }
        }

        int total = (n * n * (n * n + 1)) / 2;
        int missing = total - (sum - dup);

        return {dup, missing};
    }
};
