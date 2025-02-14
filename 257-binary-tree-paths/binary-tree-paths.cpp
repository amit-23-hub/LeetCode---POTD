class Solution {
public:
    vector<string> solve(TreeNode* root, vector<string>& ans, string temp) {
        if (!root) return ans; // Base case to handle null nodes
        
        temp += to_string(root->val);
        
        if (!root->left && !root->right) {
            ans.push_back(temp);  // If leaf node, add path to ans
        }
        
        if (root->left) {
            solve(root->left, ans, temp + "->");
        }
        if (root->right) {
            solve(root->right, ans, temp + "->");
        }

        return ans;
    }
     
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root) return {};
        
        return solve(root, ans, "");
    }
};
