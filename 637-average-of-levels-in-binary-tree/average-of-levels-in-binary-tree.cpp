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
    vector<double> averageOfLevels(TreeNode* root) {
        
        queue<TreeNode*>q ; 
        vector<double>ans ; 
        q.push(root) ; 

        while(!q.empty()){
            int t = q.size() ;
            int tt = t ; 
            double sum = 0 ; 
            while(tt--){
            TreeNode* f = q.front();
             q.pop() ; 
             sum+=f->val ; 
            if(f->left){
             q.push(f->left) ; 
          }if(f->right){
              q.push(f->right) ;
          }

            }
            ans.push_back(sum/t) ; 

        }

        return ans ;
    }
};