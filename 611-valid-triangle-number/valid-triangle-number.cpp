class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        int n = nums.size() ; 
        sort(nums.begin() , nums.end()) ; 

        int cnt = 0  ; 

        for(int k = n-1 ; k>=2 ; k--){
            int i = 0 , j=k-1 ; 
            while(i<j){
                if(nums[i]+nums[j]>nums[k]){
                  cnt+= (j-i ) ; // it is arrangd in asc...
                  j-- ; 
                }else{
                    i++ ; 
                }
            } 
        }
        return cnt ; 
    }
};