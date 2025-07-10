class Solution {
public:
    bool containZero(vector<int>& nums){
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0){
                return true; 
            }
        }
        return false; // Missing earlier
    }

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> ans(n, 0);

        int zeroCount = 0;
        long long product = 1;

        // First pass to count zeros and calculate product of non-zero elements
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                zeroCount++;
                if(zeroCount > 1) return ans; // More than one zero, all outputs will be 0
            } else {
                product *= nums[i];
            }
        }

        // If exactly one zero
        if(zeroCount == 1) {
            for(int i = 0; i < n; i++) {
                if(nums[i] == 0) {
                    ans[i] = product;
                    break;
                }
            }
        }
        // No zeros
        else {
            for(int i = 0; i < n; i++) {
                ans[i] = product / nums[i];
            }
        }

        return ans;
    }
};
