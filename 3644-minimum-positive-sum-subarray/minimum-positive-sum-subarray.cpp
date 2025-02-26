class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size() ; 
       int minsum = INT_MAX ;
        for(int i = 0 ; i<n;i++ ){
             int sum = 0 ; 
            for(int j = i ; j<n ;j++){
                sum=sum+nums[j] ; 
                if(sum>0&&(j-i+1)>=l&&(j-i+1)<=r){
                minsum = min(minsum,sum) ;
            }
            }

            
        }
        if(minsum==INT_MAX) return -1 ;
        return minsum ;
    }
};