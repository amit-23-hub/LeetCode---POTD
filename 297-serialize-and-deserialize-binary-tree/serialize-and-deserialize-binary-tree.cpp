class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            if (cur) {
                s.append(to_string(cur->val) + ",");
                q.push(cur->left);
                q.push(cur->right);
            } else {
                s.append("#,");
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
           // Converts the data string into a stream so we can read parts of it sequentially  with help getline 
        stringstream s(data);
        string str;
        getline(s, str, ',');  // iss string ki 1st value mil jayegi jo oot hogi

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Left child
            if (getline(s, str, ',')) {
                if (str != "#") {
                    TreeNode* leftNode = new TreeNode(stoi(str));
                    node->left = leftNode;
                    q.push(leftNode);
                }
            }

            // Right child
            if (getline(s, str, ',')) {
                if (str != "#") {
                    TreeNode* rightNode = new TreeNode(stoi(str));
                    node->right = rightNode;
                    q.push(rightNode);
                }
            }
        }

        return root;
    }
};
