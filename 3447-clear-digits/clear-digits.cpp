class Solution {
public:
    string clearDigits(string s) {
        int i = 0;
        while (i < s.size()) {
            if (isalpha(s[i])) {
                i++; // Move forward if it's a letter
            } else {
                if (i > 0) {
                    s.erase(i - 1, 2); 
                    i = max(i - 2, 0); 
                } else {
                    s.erase(i, 1); 
                }
            }
        }
        return s;
    }
};
