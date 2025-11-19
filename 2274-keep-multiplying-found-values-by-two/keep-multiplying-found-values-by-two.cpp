class Solution {
public:
    int findFinalValue(vector<int>& nums, int ori) {
        int n = nums.size() ; 
        
        sort(nums.begin() , nums.end()) ;
        for(int i = 0 ; i <n ; i++){
            if(nums[i]==ori){
                ori = 2*ori ; 
            }
        }
        return ori ;
    }
};