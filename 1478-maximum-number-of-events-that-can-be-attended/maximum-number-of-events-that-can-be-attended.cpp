class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin() , events.end()) ; 
         int n  = events.size() ; 
         priority_queue<int , vector<int> , greater<int>> p ; 
             int cnt = 0 ; 
             int day = events[0][0] ;
               int i = 0 ; 
             while(i<n || !p.empty()){

                while(i<n && day==events[i][0]){
                      p.push(events[i][1])     ;         // jis din end ho raha uske store kra lenge 
                      i++ ; 
                }

                // pop krenge event attend kr k ek din me ek bs 
                if(!p.empty()){     // agr queue khali nhi hai mtlb is din koi vent hoga use attend kr lenge
                   
                  p.pop() ; 
                  cnt++ ; 
       
                  
                }
                 day++ ; 
                // agr koi event miss out ho gya to usse hata denge 

                  while ( !p.empty()  && p.top()<day ){
                           p.pop() ; 
                  }
             } 
       
        return cnt ; 
    }
};

