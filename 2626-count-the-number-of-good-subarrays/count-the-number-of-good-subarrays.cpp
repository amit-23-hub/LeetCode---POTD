class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        long long res = 0;
        unordered_map<int, int> mp;
        long long pair = 0;

        while (j < n) {
            pair += mp[nums[j]];
            mp[nums[j]]++;


            ///  srinking kr rhe 
            while (pair >= k) {
                res += (n - j);  // all subarrays from i to j, j+1, ..., n-1 are valid
                mp[nums[i]]--;
                pair -= mp[nums[i]];
                i++;
            }
            j++;
        }

        return res;
    }
};
