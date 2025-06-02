class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        // mid nikal lo 
        // check kro agr mid k right me even number hai to 
        // 1. agr nums[mid] = nums[mid+1] then idhar hi requre element hoga 
        // agr nhi equal hai to left side me hoga 

        int n = nums.size(); 
        int l = 0; 
        int h = n - 1; 

        while (l < h) {
            int mid = l + (h - l) / 2;

            // Ensure mid is even for pair checking
            if (mid % 2 == 1) {
                mid--; // Make mid even
            }

            if (nums[mid] == nums[mid + 1]) {
                l = mid + 2;
            } else {
                h = mid;
            }
        }

        // l will point to the single non-duplicate element
        return nums[l];
    }
};
