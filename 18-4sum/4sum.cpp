class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int x) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicates for i

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;  // Skip duplicates for j

                long long  req = (long long)x - nums[i] - nums[j];
                int l = j + 1;
                int r = n - 1;

                while (l < r) {
                    long long sum = nums[l] + nums[r];
                    if (sum == req) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l + 1]) l++;  // Skip duplicates
                        while (l < r && nums[r] == nums[r - 1]) r--;  // Skip duplicates
                        l++;
                        r--;
                    } else if (sum < req) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }

        return ans;
    }
};
