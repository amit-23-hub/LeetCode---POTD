class Solution {
public:
    bool isHappy(int n) {
        int orgn = n;
        
        while (true) {
            int sum = 0;
            while (orgn > 0) {
                int rem = orgn % 10;
                sum += rem * rem; 
                orgn /= 10;
            }
            if (sum == 1) return true;   // happy number found
            if (sum == 4) return false;  // cycle detected
            orgn = sum; // continue with new number
        }
    }
};
