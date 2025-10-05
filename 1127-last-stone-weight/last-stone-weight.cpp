class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> mh;  
            int n = stones.size() ; 
        for(int i = 0 ; i<n ; i++){
            mh.push(stones[i]) ; 
        }

        while(mh.size() > 1){
            int s1 = mh.top();
            mh.pop() ; 
            int s2 = mh.top()  ; 
            mh.pop() ; 
            if(s1!=s2){
                int newS = s1-s2 ; 
                mh.push(newS) ; 
            }
        }
          return mh.empty() ? 0 : mh.top(); 
    }
};