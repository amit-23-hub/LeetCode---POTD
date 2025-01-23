class Solution {
public:
     int solve(int n , vector<int>&dp){
        if(n<=1){
            return 1 ; 
        }
        if(dp[n]!=-1){
            return dp[n] ; 
        }
       int oneStep = solve(n - 1, dp); // Taking 1 step
        int twoStep = solve(n - 2, dp); // Taking 2 steps
        return dp[n] = oneStep + twoStep ;  
     }
   
    int climbStairs(int n) {
        vector<int>dp(n+2 , -1) ; 
        return solve(n,dp) ; 
    }
};