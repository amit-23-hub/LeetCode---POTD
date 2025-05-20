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
int maxSum ;  

int solve(TreeNode* root){
    if(!root)return 0 ; 
    int l = solve(root->left) ;   // left traverse krne k liye
    int r  = solve(root->right) ;   // right k liye

    int niche_ans_mil_gya = l+r+root->val ;    // case 1 
    int koi_ek_achha  = max(l,r) + root->val ; // case 2 
    int bs_root_acha = root->val ;     ///  case 3 
    maxSum  = max({maxSum,niche_ans_mil_gya,koi_ek_achha,bs_root_acha }) ; 

    /// return bas 2nd and 3rd ko kr skte hai 
    return max(koi_ek_achha,bs_root_acha) ;

}
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN ;
        solve(root) ; 
        return maxSum ; 
    }
};