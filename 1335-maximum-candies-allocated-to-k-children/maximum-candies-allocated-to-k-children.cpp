class Solution {
public:
    int maximumCandies(vector<int>& c, long long k) {
        int n = c.size();
        int left = 1, right = *max_element(c.begin(), c.end()), ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long count = 0;

            for (int i = 0; i < n; i++) {
                count += c[i] / mid; 
            }

            if (count >= k) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};
