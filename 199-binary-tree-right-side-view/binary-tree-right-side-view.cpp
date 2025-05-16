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
    vector<int> rightSideView(TreeNode* root) {

       

        vector<int>ans  ; 
          if (!root){
            return ans  ;
        }
        queue<TreeNode*>q ; 
        q.push(root) ; 

        while(!q.empty()){

            int n = q.size()  ;

            for(int i = 0 ; i<n ; i++){ // 1st root k liye 1 bar loop chalega and then root ko pop krenge then 2 and 3 inset hoga to size 2 ho jayega aur hmesha right side wala lena tha i = n-1  = 1 index wala lenge ans so on .........

                TreeNode* temp = q.front() ; 
                q.pop();

                if(i==n-1){
                    ans.push_back(temp->val)  ;
                }

                if(temp->left ){
                    q.push(temp->left) ; 
                }
                if(temp->right){
                    q.push(temp->right ) ;
                }

            }
        }

        return ans  ;  
        
    }
};