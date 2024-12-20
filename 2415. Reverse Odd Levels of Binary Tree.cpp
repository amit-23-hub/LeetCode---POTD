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
    TreeNode* reverseOddLevels(TreeNode* root) {
        // sbko queue me dalenge agr 
        // har level k element ko ek vector me store kr lenge 
        // agr level odd rha to swap kr denge 

        queue<TreeNode*>q; 
        q.push(root) ; 
        int level = 0 ; 

        while(!q.empty()){
          int k =q.size() ; 
          vector<TreeNode*>curr_level ; 

          for(int i = 0 ; i<k ; i++){
            TreeNode* curr  =  q.front() ; 
            q.pop() ; 
            curr_level.push_back(curr) ; 

            if(curr->left){
                q.push(curr->left ) ; 
            }
            if(curr->right){
                q.push(curr->right) ;
            }
          }
          // level reverse krne k liye 
          if((level%2)!=0){
            int n = curr_level.size(); 
            for(int j  = 0 ; j<n/2 ; j++){
                   swap(curr_level[j]->val, curr_level[n - j - 1]->val);
            }
          }
          level++ ; 
        }
        return root ;
    }
};