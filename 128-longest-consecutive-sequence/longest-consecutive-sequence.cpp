class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        map<int, int> mp;
        for (int num : nums) {
            mp[num] = 1;  // mark number as present
        }

        int longest = 1;
        int currLen = 1;
        int prev = mp.begin()->first;

        for (auto it = next(mp.begin()); it != mp.end(); ++it) {
            if (it->first == prev + 1) {
                currLen++;
            } else {
                longest = max(longest, currLen);
                currLen = 1;
            }
            prev = it->first;
        }

        longest = max(longest, currLen);  // last check
        return longest;
    }
};
