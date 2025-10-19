class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> visited;
        queue<string> q;
        q.push(s);
        string smallest = s;
        int n = s.size();

        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            if (visited.count(cur)) continue;
            visited.insert(cur);
            smallest = min(smallest, cur);

            // Add operation: increase digits at odd indices
            string added = cur;
            for (int i = 1; i < n; i += 2) added[i] = ((added[i] - '0' + a) % 10) + '0';

            // Rotate operation
            string rotated = cur.substr(n - b) + cur.substr(0, n - b);

            if (!visited.count(added)) q.push(added);
            if (!visited.count(rotated)) q.push(rotated);
        }

        return smallest;
    }
};
