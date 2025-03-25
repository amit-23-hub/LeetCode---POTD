class Solution {
public:
    bool check(int divisor, int num) {
        return divisor != 0 && num % divisor == 0;
    }

    int divisorSubstrings(int num, int k) {
        int cnt = 0;
        string s = to_string(num);
        
        for (int i = 0; i <= s.size() - k; i++) {
            string sub = s.substr(i, k); // Extract k-size substring
            int val = stoi(sub);
            
            if (check(val, num)) {
                cnt++;
            }
        }
        
        return cnt;
    }
};
