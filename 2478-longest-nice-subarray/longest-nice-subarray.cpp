class Solution {
public:

   // agar  isme x^y^z.. == x+y+z hai to uska bitwise AND zero hoga 
   //  3 -> 011
   //  8 ->1000
   //  11 and xor 1011 and dono equal bhi hai 
   // niceh sliding windo se solve kiye hai
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size() ; 
        int l = 0 ; 
        int r = 0 ; 
        int maxSize = 0 ; 
       int  cur_sum = 0 ;
    int xor_sum = 0 ;
        while(r<n){
          cur_sum +=nums[r] ; 
          xor_sum ^= nums[r] ; 
          while(cur_sum!=xor_sum){
            cur_sum-=nums[l] ; 
            xor_sum ^= nums[l] ; 
            l++ ; 
          }  

          maxSize = max(maxSize , r-l+1);
          r++;
         
        }

        return maxSize; 
    }
};