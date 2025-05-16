class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // starrting me sort kr denge 
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicate elements
            int l = i + 1;   // left pointer lenge
            int r = n - 1;       // right pointer lenege 
            
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) l++;  // Skip duplicate elements
                    while (l < r && nums[r] == nums[r - 1]) r--;  // Skip duplicate elements
                    l++;
                    r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        
        return ans;
    }
};
