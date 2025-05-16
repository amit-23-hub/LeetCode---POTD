class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> st; 
        int l = 0, maxlen = 0;

        for (int r = 0; r < n; ++r) {
            // If character is already , tab hm left pointer ko badha denge aur uss left position pr jo char hai use hata denge 
            while (st.find(s[r]) != st.end()) {         // ye line check krega weather element set me hai ya nhi  
                st.erase(s[l]);
                l++;
            }
            // Add the current character to the set and update max length
            st.insert(s[r]);
            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};
