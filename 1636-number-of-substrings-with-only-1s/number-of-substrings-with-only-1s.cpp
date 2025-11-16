class Solution {
public:
    long long cntt(long long n){
        return n*(n+1)/2;
    }

    int numSub(string s){
        const long long mod = 1000000007;
        int n = s.size();
        long long ans = 0;

        for(int i = 0; i < n; i++){
            long long cnt = 0;
            
            while(i < n && s[i] == '1'){
                cnt++;
                i++;
            }

            ans = (ans + cntt(cnt)) % mod;
        }

        return (int)ans;
    }
};
