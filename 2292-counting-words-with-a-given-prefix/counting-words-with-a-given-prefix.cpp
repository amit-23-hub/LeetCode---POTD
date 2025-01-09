class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt =0 ;
        for(int p = 0 ; p<words.size() ; p++){
            int i =0 , j=0;
            while(i<words[p].size() && j <pref.size()){
                if(words[p][i]==pref[j]){
                    i++ ;
                    j++ ;
                }else break ;
            }
            if (j==pref.size()) cnt++ ;
        }
        return cnt ;
    }
};