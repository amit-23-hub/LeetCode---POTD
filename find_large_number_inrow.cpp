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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans ; 
        if(root==NULL){
            return ans; 
        }
        queue<TreeNode*>q ; 
        q.push(root) ; 
        while(!q.empty()){
            int k  = q.size() ; 
             priority_queue<int>maxH ;
            while(k--){
                TreeNode* temp = q.front() ; 
                q.pop() ; 
                maxH.push(temp->val) ; 
                if(temp->left){
                    q.push(temp->left) ; 
                }
                if(temp->right){
                    q.push(temp->right) ; 
                }

            }
            ans.push_back(maxH.top()) ; 
        }
        return ans  ;
    }
};