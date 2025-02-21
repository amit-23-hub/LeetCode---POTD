class FindElements {
public:
    TreeNode* root;  

    void dfs(TreeNode* node, int x) {
        if (!node) return;

        node->val = x;  

        if (node->left) dfs(node->left, 2 * x + 1);
        if (node->right) dfs(node->right, 2 * x + 2);
    }

    bool findTar(TreeNode* node, int x) {
        if (!node) return false;  
        if (node->val == x) return true;  

        return findTar(node->left, x) || findTar(node->right, x);  
    }
    
    FindElements(TreeNode* root) {
        this->root = root;
        dfs(root, 0);
    }
    
    bool find(int x) {
        return findTar(root, x);
    }
};
