class Solution {
public:
   bool check(string s ){
    for(int i = 0 ; i<s.size();i++){

        char c  = s[i] ; 
        if(c<=90){
            c+=32 ; 
        }else{
            c-=32 ; 
        }
        // check it presencs
        if(s.find(c)==string::npos) return false ; 
    }

    return true  ; 
   }

    string longestNiceSubstring(string s) {
        string ans = "" ; 
        int n = s.size() ; 
        for(int i = 0 ; i <n ; i++){
            string res = "" ;
            res+= s[i] ;  
            for(int j = i+1 ; j<n ; j++){
                     res+=s[j] ; 
                     if(check(res) && res.size()>ans.size()){
                        ans = res ; 
                     }
            } 
        }

        return ans  ;
    }
};