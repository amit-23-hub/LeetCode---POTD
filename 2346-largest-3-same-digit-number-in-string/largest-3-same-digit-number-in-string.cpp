class Solution {
public:
    string largestGoodInteger(string num) {
        string store = "";
        for (int i = 0; i <= (int)num.size() - 3; i++) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                string trip = num.substr(i, 3);
                if (store < trip) {
                    store = trip;
                }
            }
        }
        return store;
    }
};
