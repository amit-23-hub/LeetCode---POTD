class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        int sz = n.size();

        for (int idx1 = 0; idx1 < sz - 1; idx1++) {
            int toFind = target - n[idx1];
            int low = idx1 + 1, high = sz - 1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (n[mid] == toFind) {
                    // Add 1 to convert to 1-based indexing
                    return {idx1 + 1, mid + 1};
                } else if (n[mid] < toFind) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return {-1, -1}; // if no such pair exists
    }
};
