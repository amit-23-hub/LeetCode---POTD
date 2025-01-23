class Solution {
public:
//  /// using Dp  memoizationn


//       int fibon(int n , vector<int>&dp){
//         if(n<=1){
//             return n ;  
//         }
//         // agr already value calculated hai to we directly use them 
//         if(dp[n]!=-1){
//             return dp[n] ; 
//         }
//         // jo value caclulate krenge use store kr lenge 
//         return dp[n] = fibon(n-1 , dp)+fibon(n-2 , dp) ;
//       }

//     int fib(int n) {
//         vector<int>dp(n+1 , -1) ; 
//         return fibon(n , dp ) ; 
//     }


// tabulation method 

// int fib(int n){
//      if(n<=1){
//         return n ; 
//      }
//     vector<int>dp(n+1) ; 
//     dp[0]=0 ; 
//     dp[1] = 1 ; 

//     for(int i =2 ; i<n+1 ; i++){
//         dp[i] = dp[i-1]+dp[i-2] ; 
//     }
//     return dp[n] ; 
// }


// space optimazation O(1) , bs 3 variable lekr solve kr denge 
int fib(int n){
     if(n<=1){
        return n ; 
     }
    int cur , pre1=1 , pre2 = 0 ; 

    for(int i =2 ; i<n+1 ; i++){
     cur = pre1+pre2 ;
     pre2=pre1 ; 
     pre1 = cur ; 
    }
    return cur ; 
}
};