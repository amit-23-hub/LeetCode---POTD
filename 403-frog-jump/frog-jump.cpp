class Solution {
public:
    unordered_map<int,int>mp ; 
    int n ; 
    vector<vector<int>>dp ; 
    bool solve (vector<int>& stones, int cur_stone_idx , int pre_jump){
        if(cur_stone_idx ==n-1){
            return true  ;  
        }

       if(dp[cur_stone_idx][pre_jump] != -1){
        return dp[cur_stone_idx][pre_jump] ;
       }

        for(int next_jump = pre_jump-1 ;next_jump<=pre_jump+1;next_jump++ ){
            // agr next jump k - 1, k, or k + 1 zero se bada hoga tabhi consider krenge 
            if(next_jump>0){
            int     next_stone = stones[cur_stone_idx]+next_jump ; 
                // next stone ko dekh lnege mp me hai ya nhi agr hoga to next stone cur_stone ban jayega and pre_jump next jump  
                if(mp.find(next_stone)!=mp.end()){
                    if( solve(stones , mp[next_stone],next_jump) ){
                        return dp[cur_stone_idx][pre_jump] = true ; 
                    } 
                }
            }
        }
        return dp[cur_stone_idx][pre_jump]=false   ; 
    }
    bool canCross(vector<int>& stones) {
        n = stones.size() ; 
         dp = vector<vector<int>>(n, vector<int>(2001, -1));
        for(int i=0;i<n ; i++){
            mp[stones[i]]=i ; 
        }

        return solve(stones,0,0);
    }
};