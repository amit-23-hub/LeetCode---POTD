class Solution {
public:
    int solve(vector<int>& nums, int i, int pre, vector<vector<int>>& dp) {

        if (i == nums.size()) {
            return 0;
        }

        if (dp[i][pre + 1] != -1) {
            return dp[i][pre + 1];
        }
        int take = 0;
        if (pre == -1 || nums[i] > nums[pre]) {
            take = 1 + solve(nums, i + 1, i, dp);
        }
         int skip = solve(nums, i + 1, pre, dp);
       
        return dp[i][pre + 1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
      
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return solve(nums, 0, -1, dp);
    }
};
