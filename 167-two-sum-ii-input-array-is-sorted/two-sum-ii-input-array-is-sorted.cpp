class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        int left = 0, right = n.size() - 1;

        while (left < right) {
            int sum = n[left] + n[right];

            if (sum == target) {
                // Return 1-based indices
                return {left + 1, right + 1};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return {-1, -1}; // no valid pair found
    }
};
