class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int, int>> st;  // pair of (temperature, index)
        vector<int> ans(t.size(), 0);

        for (int i = 0; i < t.size(); i++) {
            while (!st.empty() && t[i] > st.top().first) {
                int prevTemp = st.top().first;
                int prevIndex = st.top().second;
                st.pop();
                ans[prevIndex] = i - prevIndex; 
            }
            st.push({t[i], i});
        }

        return ans;
    }
};
