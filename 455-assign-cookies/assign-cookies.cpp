class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int c = 0 ; 
        // grid factor me se se lenege dekhene agr uske size ka hai cookie to assign krke c++ ,
        
        // sort(g.begin() , g.end());
        // sort(s.begin() , s.end());

        //  int i = 0, j = 0, c = 0;
        
        // while(i < g.size() && j < s.size()) {
        //     if(s[j] >= g[i]) { // Cookie satisfies child's greed
        //         c++;
        //         i++; // Move to next child
        //     }
        //     j++; // Always move to next cookie
        // }
        priority_queue<int, vector<int>, greater<int>> h1;
        priority_queue<int, vector<int>, greater<int>> h2;
        for(int i = 0 ; i<g.size() ; i++){
            h1.push(g[i]) ; 
        }

        for(int i = 0 ; i<s.size() ; i++){
            h2.push(s[i]) ; 
        }

       while(!h1.empty() && !h2.empty()){ 

            int gg = h1.top() ; // student 
            int ss = h2.top() ;       // cookie 
            if(ss>=gg){
                c++ ; 
                h1.pop() ; 
                h2.pop() ; 
            }else{
                h2.pop() ; 
            }
        }

        return c ;
    }
};