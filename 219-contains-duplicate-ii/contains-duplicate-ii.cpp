class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp ; 

        // check kr lenge agr vo number hoga and index ka difference lsess hoga then retur true otherwise false  ; 

        for(int i = 0 ; i < nums.size() ; i++){
            if(mp.find(nums[i])!=mp.end()  && abs( mp[nums[i]]-i) <=k){
            return true  ;
            }else{
                mp[nums[i]] = i ; 
            }
        }

        return false  ;  
    }
};