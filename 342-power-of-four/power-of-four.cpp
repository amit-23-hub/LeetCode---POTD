class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0 ){
            return false ; 
        }
        if(n==1 || n==4){
            return true ; 
        }

        for(int i = 0 ; pow(4,i)<=n ; i++){
            if(pow(4,i)==n){
                return true ; 
            }
        }

        return false ;
        
    }
};