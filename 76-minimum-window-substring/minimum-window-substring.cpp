// class Solution {
// public:
//     // ab ye freq ke hisaab se check karega
//     bool iscontain(const string &s, const string &t) {
//         unordered_map<char,int> need, have;
//         for (char c : t) need[c]++;
//         for (char c : s) have[c]++;
//         for (auto &p : need) {
//             if (have[p.first] < p.second) return false;
//         }
//         return true;
//     }
    
//     string minWindow(string s, string t) {
//         int n = s.size();
//         int r;
//         int l = 0; 
//         int len = INT_MAX;  
//         int start = 0;  // answer start index
//         string temp = ""; 
        
//         for (r = 0; r < n; r++) {
//             temp += s[r]; // window expand

//             while (iscontain(temp, t)) { // jab tak window valid hai
//                 if (r - l + 1 < len) {
//                     len = r - l + 1;
//                     start = l;
//                 }
//                 temp.erase(temp.begin()); // left se shrink
//                 l++;
//             }
//         }
        
//         return (len == INT_MAX) ? "" : s.substr(start, len);
//     }
// };


class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need;
        for (char c : t) need[c]++;
        
        unordered_map<char,int> have;
        int count = 0;  // kitne chars t ke abhi tak match ho gaye
        int l = 0, len = INT_MAX, start = 0;
        
        for (int r = 0; r < s.size(); r++) {
            have[s[r]]++;
            
            if (need.count(s[r]) && have[s[r]] <= need[s[r]]) {
                count++;
            }
            
            while (count == t.size()) {  // ab window valid hai
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    start = l;
                }
                
                have[s[l]]--;
                if (need.count(s[l]) && have[s[l]] < need[s[l]]) {
                    count--;
                }
                l++;
            }
        }
        
        return (len == INT_MAX) ? "" : s.substr(start, len);
    }
};
