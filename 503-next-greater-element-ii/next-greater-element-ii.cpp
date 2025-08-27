class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size() ; 
        vector<int>ans(n , -1) ; 
        stack<int>st  ; 

        for(int j = 2*n-1 ; j>=0 ; j--){
               while(!st.empty() && st.top() <=nums[j%n]){
                st.pop() ; 

               } ; 
               if(j<n){
ans[j] = st.empty() ?-1 : st.top() ; 
               }
            st.push(nums[j%n] ) ; 
        }

       return ans ; 
    }
};