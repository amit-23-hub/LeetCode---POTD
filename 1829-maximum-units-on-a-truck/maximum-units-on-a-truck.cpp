class Solution {
public:
    int maximumUnits(vector<vector<int>>& b, int k) {
        
        int ans=0  ; 
       vector< pair<int,int>>v  ;  
        for(int i = 0 ; i<b.size() ; i++ ){
            
            v.push_back({b[i][1],b[i][0] }) ; 
        }
        sort(v.rbegin(), v.rend());
        for(int i = 0 ; i<v.size() ; i++){
            int n1 = v[i].first ; 
            int n2  = v[i].second ; 
             if (n2 <= k) {  
                ans += n2 * n1;  
                k -= n2;  
            } else {  
                ans += k * n1;  
                k = 0;  
            }

            if (k == 0)  
                break;  
        }
        return ans;  
    }
};