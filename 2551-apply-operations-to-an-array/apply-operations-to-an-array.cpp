class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
     for(int i=0; i < nums.size()-1; i++) {
            if(nums[i] == nums[i+1]) {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        vector<int> ans;
        for(int i = 0 ; i<nums.size() ; i++) {
        if(nums[i]){
        ans.push_back(nums[i]); 
        }
        }
        for(int i=ans.size(); i<nums.size(); i++){ 
             ans.push_back(0);
        }
        return ans;
    }
};