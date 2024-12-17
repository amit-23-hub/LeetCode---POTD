class Solution {
public:
    typedef pair<char, int> P; // Typedef for a pair 
    
    
    struct Operation {
        bool operator()(P &p1, P &p2) {
            return p1.first < p2.first; // Max-heap banane k liye 
        }
    };

    string repeatLimitedString(string s, int repeatLimit) {
        // store character counts
        unordered_map<char, int> mp;

        // Count frequency of each character
        for (auto c : s) {
            mp[c]++;
        }

        // Max-heap
        priority_queue<P, vector<P>, Operation> mh;

        // Push kr denge max heap me sare char, freq ko 
        for (auto &it : mp) {
            mh.push({it.first, it.second});
        }

        string ans = ""; // Resultant string

        // Process characters from the max-heap
        while (!mh.empty()) {
            P temp = mh.top();
            mh.pop();

                  // jo chhota hoga use le lenge 
            int useCount = min(temp.second, repeatLimit);
            ans.append(useCount, temp.first);         // chhota numbeer k bararbar append kr denge ans me 
            temp.second -= useCount;             // aisa bhi ho skta agr temp.secod bada ho to uski freq. bachi ho to use store kr le rhe 

            if (temp.second > 0) {
                // If there are more characters left, we need a break character
                if (mh.empty()) {
                    // No other character
                    break;
                }

                // Pop kr denge agla top ko 
                P next = mh.top();
                mh.pop();

                // bs iska 1 hi character use krenge fir se temp wala hi use krenge for lexicographically largest
                ans.push_back(next.first);
                next.second--;      // uske frequency ko dercres kr diye 

                // Push the remaining counts back to the heap
                if (next.second > 0) {
                    mh.push(next);
                }
                mh.push(temp); //  jo original tha use push kr denge 
            }
        }

        return ans;
    }
};