class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0)return false ; 
        if(n==1 || n==3 )return true ;
        for(int i = 1 ;pow(3,i) <=n;i++){
            if(pow(3,i)==n)return true  ; 
        }

        return false ;
    }
};