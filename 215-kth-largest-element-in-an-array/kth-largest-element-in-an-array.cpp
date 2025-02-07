class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>mh ; 
        for(int i = 0 ; i<nums.size() ;i++){
            mh.push(nums[i]) ; 
        }

        while(k>1){
            mh.pop() ;
            k-- ;  
        }
        return mh.top() ; 

    }
};