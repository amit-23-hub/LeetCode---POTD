class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // int n = nums.size();
        // int maxxn = 0;

        // for (int i = 0; i < n; i++) {
        //     int cnt = 0;  
        //     for (int j = i; j < n; j++) {
        //         if (nums[j] == 0) {
        //             if (cnt < k) cnt++;
        //             else break;  // Stop if more than k zeroes are encountered
        //         }
        //         maxxn = max(maxxn, j - i + 1);
        //     }
        // }

        // return maxxn;

        // sliding window 

        int r  = 0 ; 
        int l = 0 ; 
        int maxl = 0 ; 
        int n = nums.size() ; 
          int cnt = 0 ;
        while(r<n){
            if(nums[r]==0){
                cnt++ ; 
            }
            while(cnt>k){
                if(nums[l] ==0 ){
                    cnt-- ; 
                    
                }
                l++ ;
            }

            maxl  = max(maxl , r-l+1) ; 
            r++;
        }

        return maxl ; 
    }
};
