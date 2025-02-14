/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(!root){return false ;}

        // agr leaf node hai to vaha se return ho aana hai 
        if(!root->left && !root->right){
            return root->val ; 
        }
        //post LRN
        // Left aur Right subtree evaluate karke store karo
        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);

        if (root->val == 2) return left || right;
        if (root->val == 3) return left && right;

     return false ; 
    }
};