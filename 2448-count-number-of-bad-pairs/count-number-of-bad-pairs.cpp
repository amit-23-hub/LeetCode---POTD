class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long tt = n * (n - 1) / 2;  // Total number of pairs
        
        unordered_map<int, long long> mp;
        long long c = 0;

        for (int i = 0; i < n; i++) {
            int key = i - nums[i];  // Transform index based on condition
            c += mp[key];  // Count pairs where val[j] == val[i] (good pairs)
            mp[key]++;
        }

        return tt - c;  // Bad pairs = Total pairs - Good pairs
    }
};
