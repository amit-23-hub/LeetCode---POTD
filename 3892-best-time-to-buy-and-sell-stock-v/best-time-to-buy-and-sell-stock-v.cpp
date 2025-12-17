class Solution {
private:
    long long dp[1001][501][3];
    long long recursion(int idx,int k,int type,vector<int>& prices){
        int n=prices.size();
        if(k==0) return 0; //transactions over
        if(idx==n-1){
            if(type==0){ // as now we can't buy or sell further so we won't include this
                return 0;
            }else if(type==1){ // to complete transaction it has to be sold
                return prices[idx];
            }else{ // to complete transaction it has to be bought
                return -prices[idx];
            }
        }
        if(dp[idx][k][type]!=-1) return dp[idx][k][type];
        long long take=LLONG_MIN; long long not_take=LLONG_MIN;
        if(type==0){ //normal transaction-> buy || short selling transaction-> sell
            long long normal_transaction_buy=-prices[idx]+recursion(idx+1,k,1,prices);
            long long short_selling_transaction_sell=+prices[idx]+recursion(idx+1,k,2,prices);
            take=max(normal_transaction_buy,short_selling_transaction_sell);
            not_take=recursion(idx+1,k,type,prices);
        }else if(type==1){ //normal transaction-> sell
            take=+prices[idx]+recursion(idx+1,k-1,0,prices);
            not_take=recursion(idx+1,k,1,prices);
        }else{ //short selling transaction-> buy
            take=-prices[idx]+recursion(idx+1,k-1,0,prices);
            not_take=recursion(idx+1,k,2,prices);
        }
        return dp[idx][k][type]=max(take,not_take);
    }
public:
    long long maximumProfit(vector<int>& prices, int k) {
        // 3 changing parameters
        // idx,k,type
        // type--->
        // 0-> max of (normal transaction-> buy) & (short selling transaction-> sell)
        // 1-> normal transaction-> sell
        // 2-> short selling transaction-> buy
        // after either 1 or 2 return back to 0
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        return recursion(0,k,0,prices);
    }
};