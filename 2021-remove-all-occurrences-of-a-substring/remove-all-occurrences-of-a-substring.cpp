class Solution {
public:
    string removeOccurrences(string s, string part) {
       int n = s.size() ; 
       int  p  = part.size()  ;

       for(int i = 0 ; i<=n-p ; i++){
        if(  s.substr(i, p) == part){
            s.erase(i,p) ; 
            i = -1;  // Restart checking from the beginning
            n = s.size();       // string s li size km ho ja rghi
        }
      
       }
       return s ; 
    }
};