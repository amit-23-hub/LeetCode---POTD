class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string temp = a;
        int c = 1; // Start with 1 as 'a' is already considered once
        
        while (a.size() < b.size()) { 
            a += temp; 
            c++; 
        }
        
        // Brute-force substring search using a for-loop
        for (int i = 0; i <= a.size() - b.size(); i++) {
            int j = 0;
            while (j < b.size() && a[i + j] == b[j]) {
                j++;
            }
            if (j == b.size()) return c; // Found match
        }

        // Add one more repetition in case b spans two concatenations
        a += temp; 
        c++;

        for (int i = 0; i <= a.size() - b.size(); i++) {
            int j = 0;
            while (j < b.size() && a[i + j] == b[j]) {
                j++;
            }
            if (j == b.size()) return c; // Found match
        }

        return -1; // If no match found
    }
};
