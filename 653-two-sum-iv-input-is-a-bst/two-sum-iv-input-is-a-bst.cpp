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
    void inorder(vector<int>&v , TreeNode* root){
        if(!root)return ; 
        // left 
        inorder(v, root->left) ; 
        // root
        v.push_back(root->val) ; 
        //right 
        inorder(v,root->right) ; 
    }
    bool findTarget(TreeNode* root, int k) {
        
        /// store in vector then find 
        vector<int>v ; 
        inorder(v,root) ; 

        /// ab vector me se check kr lenge 
        int i = 0 ; 
        int j = v.size()-1 ; 
        while(i<j){
            if(v[i]+v[j]==k){
                return true ;
            }
            if(v[i]+v[j]<k){
                i++ ;
            }
            if(v[i]+v[j]>k){
                j-- ;
            }
        }

        return false ;
    }
};