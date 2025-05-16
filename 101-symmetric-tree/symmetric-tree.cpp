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
       bool check(TreeNode* l , TreeNode* r){

        if(!l && !r) {   /// dono null hai
       return true  ; 
        }     

        // koi ek null hoga to false 
        if(l==NULL || r== NULL){
            return false  ;  
        }     

        // value check kr lenge agr equal honge to unke child check kr lenge 

        if((l->val == r->val) && check(l->left ,r->right) && check(l->right , r->left) ){
            return true ; 
        } 

        return false ;  
       }

    bool isSymmetric(TreeNode* root) {
        

             if(!root){
                return true  ; //  empty tree always symmetric 
             }
        return   check(root->left , root->right) ; 
    }
};