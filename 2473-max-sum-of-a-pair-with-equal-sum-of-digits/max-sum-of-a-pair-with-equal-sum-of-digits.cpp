class Solution {
public:
     int sum (int  i ){
        int sum = 0 ;
          while(i>0){
          int r = i%10 ; 
          sum+=r ; 
          i=i/10 ; 
          }
          return sum ; 
     }
    int maximumSum(vector<int>& nums) {
        // tle 
    //     int n = nums.size() ; 
    //     priority_queue<int>p ; 
    //     for(int i=0;i<n;i++){
    //         for(int j = 0 ;j<n;j++){
    //               if(i!=j &&sum(nums[i])==sum(nums[j])){
    //                 p.push(nums[i]+nums[j]) ; 
    //               }
    //         }
    //     }
    //    return p.empty() ? -1 : p.top();

// approach 
// digit ka sum and kitne number k sum of digit sme aa rha uak ek array bana lenege dono ko map me store kr lenge then jis array ka size 2 se jyda hoga use le lenge kyuki usme digit ka ka sum same aaye honge 
       int n = nums.size() ; 
        int maxs = -1 ; 
     unordered_map<int, vector<int>> mp;
      for(int i = 0 ; i<n;i++){
      int s = sum(nums[i]) ;
      mp[s].push_back(nums[i]);
      }
      
      for(auto &m :mp){
        if(m.second.size()>=2){
            sort(m.second.rbegin(),m.second.rend());
            int ans  = m.second[0]+m.second[1] ;
            maxs = max(ans , maxs) ; 
        }
      }
            return maxs ; 
    }
};