class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size() ; 
        int sum = nums[0] ; 
        int cur = nums[0] ; 
        for(int i = 1 ; i<n;i++){
            if(nums[i-1]<nums[i]){
                cur+=nums[i] ; 
            }else{
           sum = max(sum, cur);
                cur = nums[i];}
        }
        return max(sum,cur) ;
    }
};