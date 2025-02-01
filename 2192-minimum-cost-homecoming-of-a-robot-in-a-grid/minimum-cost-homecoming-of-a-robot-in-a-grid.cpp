class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int totalCost = 0;

        // Move vertically (row-wise)
        if (startPos[0] < homePos[0]) {
            for (int i = startPos[0] + 1; i <= homePos[0]; ++i) {
                totalCost += rowCosts[i];
            }
        } else {
            for (int i = startPos[0] - 1; i >= homePos[0]; --i) {
                totalCost += rowCosts[i];
            }
        }

        // Move horizontally (column-wise)
        if (startPos[1] < homePos[1]) {
            for (int i = startPos[1] + 1; i <= homePos[1]; ++i) {
                totalCost += colCosts[i];
            }
        } else {
            for (int i = startPos[1] - 1; i >= homePos[1]; --i) {
                totalCost += colCosts[i];
            }
        }

        return totalCost;
    }
};
