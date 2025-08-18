
// bruteforce 
// class Solution {
// public:
//     double new21Game(int n, int k, int maxpts) {

//        vector<double>p(n+1 , 0.0) ; 

//        p[0] = 1 ;  //  prbabilty of 0 is 1 as she satart from 0 

//        for(int i = 1 ; i <= n;i++){
//         for(int j=1 ; j<=maxpts;j++){
//             if(i-j>=0 && i-j<k){
//             p[i] = p[i]+p[i-j]*1/maxpts ;
//              }
//         }
//        } 

//        return accumulate(p.begin()+k , p.end() , 0.0) ; 
//     }
// };


class Solution {
public:
    double new21Game(int N, int K, int maxPts) {
        if (K == 0 || N >= K - 1 + maxPts) return 1.0;
        vector<double> dp(N + 1, 0.0);
        dp[0] = 1.0;
        double windowSum = 1.0, probability = 0.0;
        for (int i = 1; i <= N; i++) {
            dp[i] = windowSum / maxPts;
            if (i < K) windowSum += dp[i];
            else probability += dp[i];
            if (i >= maxPts) windowSum -= dp[i - maxPts];
        }
        return probability;
    }
};
