class Solution {
public:


     //sbko stack me dalenge 
     // agr array empty hoaga to dal denge 
     // check krnge ki arr{i}<top 
     // push max(x,st.top)
     // badd me stack ki size return kr denge
    int maxChunksToSorted(vector<int>& arr) {
        
        stack<int>st ; 

        for(int i = 0 ; i<arr.size();i++){
            int x   =  arr[i] ; 
            while(!st.empty()&& arr[i]<st.top()){
                x = max(x,st.top()) ; 
                st.pop() ; 
            }
            st.push(x) ; 

        }
        return st.size() ; 
    }
};