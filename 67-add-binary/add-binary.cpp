class Solution {
public:
    string addBinary(string a, string b) {

       string ans = ""; 
       int size1 =  a.size() -1 ; 
       int size2 = b.size() -1 ; 

       int c = 0 ; 

       while(size1>=0 || size2>=0 || c){

        int sum = c ; /// agr carry hoga to
        if(size1>=0){
            sum= sum+a[size1]-'0' ; 
            size1-- ; 
        }
        if(size2>=0){
            sum= sum+b[size2]-'0' ; 
            size2-- ; 
        }
        ans += char((sum % 2) + '0');   // res ko ans me store kr denge 
        c = sum/2 ;  //  new caary
       }



        reverse(ans.begin(), ans.end());
        return ans;
    }
};