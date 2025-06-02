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

/// inorder traversal sorted hota hai 
 /// pahle left ko insert then ushko pop krke  agr uska right hoga to uske left ko dal denge jissse traversal stack ki help se sorted order me hoga 
class BSTIterator {
public:
    stack<TreeNode*>s ; 
    BSTIterator(TreeNode* root) {
        TreeNode* it = root ; 
        while(it){
            s.push(it) ; 
            it=it->left ;
        }
    }
    
    int next() {
        // ise function ko call krne pr top ki vslue return ho jaye and iske right element k left tree ko stack me dalna hai 

        TreeNode* top = s.top() ; 
        int ans = top->val ; 
        s.pop() ; 
         TreeNode* it = top->right;
      while(it){
        s.push(it);
        it=it->left ; 
        
      }

        return ans ; 

    }
    
    bool hasNext() {
        return !s.empty() ;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */