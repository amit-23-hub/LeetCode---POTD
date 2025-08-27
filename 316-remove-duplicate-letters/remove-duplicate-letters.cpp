class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>countchar(26,0) ; 


        for(char ch : s){
            countchar[ch-'a']++ ; 
        }
        stack<char>st ; 
        vector<bool>seen(26,false) ; 

        for(char ch : s){
            // pahle to jis char ko process kr rhe usko dercrese kr denge 
            countchar[ch-'a']-- ; 
            if(seen[ch-'a']){
                continue ; 
            }
            // agr aose nhi hai to monotonic stack waala concept laga denge 
            while(!st.empty() && ch<st.top() && countchar[st.top()-'a']>0){
                  char remove = st.top() ; 
                  st.pop() ; 
                  seen[remove - 'a'] = false ; 
            }
            // ab jo aayega vo chota hoga usko le lenge seen kr denge 
            st.push(ch) ; 
            seen[ch-'a'] = true ; 
        }

        string res = "" ; 
        while(!st.empty()){
            res = st.top()+res ; 
            st.pop() ; 
        }
        return res ; 
    }
};