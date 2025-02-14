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

     int solve(TreeNode* root , int d){
        if(!root){
            return INT_MAX ; // base case : large value return kr denge to minimum wala automatice aa jayega 
        }
       
    if (!root->left && !root->right) return d;  //  agr leaf node pr pahuch gye to return aa jana hai
     int left  =   solve(root->left ,d+1) ;
     int right = solve(root->right , d+1) ; 

     return min(left,right) ; 
     }
    int minDepth(TreeNode* root) {
        if(!root){
            return 0 ; 
        }
        int d = 1 ; 
      return  solve(root , d) ; 

        
    }
};