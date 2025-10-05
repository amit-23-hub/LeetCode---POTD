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
// fn to check identical 
 bool isSameTree(TreeNode*p , TreeNode* q) {
    if(p==NULL && q==NULL)return true ; 

     if((p&&!q)||(!p&&q)){
            return false ;
           }
    if(p->val != q->val){
            return false ;
           }
         return  isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
 

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
     // subtree left me hoga ya right side me 
     // both side recruion laga k check kr le agr match krega then return true    
     // agr root null to no subtree
     if(root == NULL){
        return false ; 
     }
     if(isSameTree(root,subRoot)) {
        return true ; 
     }
     // jidhar se substree match krega vaha se return kra denge
     return isSubtree(root->left , subRoot) || isSubtree(root->right , subRoot) ; 
    }
};