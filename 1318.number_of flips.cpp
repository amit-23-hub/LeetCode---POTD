class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int flip = 0  ; 
        while(a!=0 || b!=0 || c!=0){
            if((c&1)==1){
                if((a &1)==0 && (b&1)==0){             /// agr hme c ko 1 banana hai to a aur b me se kisi ko ek 1 hona padega 
                    flip++ ; 
                }
            }else if ((c&1)==0){        //  c ko 0 bananne k liye a and b dono ko 0 hona padega 
                if((a&1)==1){
                    flip++ ; 
                }
                if((b&1)==1){
                    flip++ ; 
                }
            }

            // abb ek ek position shift kr dnege 
            a>>=1 ;
            b>>=1 ; 
            c>>=1; 
        }
        return flip ; 
    }
};