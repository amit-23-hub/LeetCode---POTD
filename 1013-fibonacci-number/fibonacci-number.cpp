class Solution {
public:
 /// using Dp  


      int fibon(int n , vector<int>&dp){
        if(n<=1){
            return n ;  
        }
        // agr already value calculated hai to we directly use them 
        if(dp[n]!=-1){
            return dp[n] ; 
        }
        // jo value caclulate krenge use store kr lenge 
        return dp[n] = fibon(n-1 , dp)+fibon(n-2 , dp) ;
      }

    int fib(int n) {
        vector<int>dp(n+1 , -1) ; 
        return fibon(n , dp ) ; 
    }
};