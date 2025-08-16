class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        long long sum = 0;
        int len = INT_MAX;

        for (int r = 0; r < n; r++) {
            sum += nums[r];  // expand window

            // shrink window while sum >= t ,, 
            while (sum >= t) {
                len = min(len, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }

        return (len == INT_MAX ? 0 : len);
    }
};
