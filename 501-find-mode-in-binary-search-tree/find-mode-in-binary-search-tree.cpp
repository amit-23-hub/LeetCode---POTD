class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if (!root) return {};

        unordered_map<int, int> m;
        queue<TreeNode*> q;
        q.push(root);

        // Level order traversal to store frequency
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            m[node->val]++;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        // Find max frequency
        int maxFreq = 0;
        for (auto &p : m) {
            maxFreq = max(maxFreq, p.second);
        }

        // Collect all values with max frequency
        vector<int> res;
        for (auto &p : m) {
            if (p.second == maxFreq) {
                res.push_back(p.first);
            }
        }

        return res;
    }
};
