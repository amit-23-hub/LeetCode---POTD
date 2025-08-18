class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int c : cards) nums.push_back((double)c);
        return dfs(nums);
    }

private:
    const double EPSILON = 1e-6;

    bool dfs(vector<double>& nums) {
        int n = nums.size();
        if (n == 1) {
            return fabs(nums[0] - 24.0) < EPSILON;
        }

        // pick two numbers
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double a = nums[i], b = nums[j];

                // store remaining numbers
                vector<double> next;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }

                // try all results of a and b
                for (double res : compute(a, b)) {
                    next.push_back(res);
                    if (dfs(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }

    vector<double> compute(double a, double b) {
        vector<double> results;
        results.push_back(a + b);
        results.push_back(a - b);
        results.push_back(b - a);
        results.push_back(a * b);
        if (fabs(b) > EPSILON) results.push_back(a / b);
        if (fabs(a) > EPSILON) results.push_back(b / a);
        return results;
    }
};