class Solution {
public:
  int solve(int i , int j ,vector<vector<int>>& oG, int m , int n ,vector<vector<int>> &dp){
 // nhi pahcuh paya to return  0  
    if (i >= m || j >= n || oG[i][j] == 1) {
        return 0 ;
       }
    // agr destination pr gya return 1 
    if(i==m-1 && j == n-1){
        return 1  ;
    }
   
   if(dp[i][j]!=-1){
    return dp[i][j] ; 
   }
        
      
      int   right = solve(i,j+1,oG,m,n,dp) ; 
      
     int  down = solve(i+1,j,oG,m,n,dp) ; 
    

       return dp[i][j]= right +down  ; 
  }
    int uniquePathsWithObstacles(vector<vector<int>>& oG) {


        int m   = oG.size() ; 
        int n  = oG[0].size() ; 
         vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0,0,oG,m,n,dp) ; 
    }
};