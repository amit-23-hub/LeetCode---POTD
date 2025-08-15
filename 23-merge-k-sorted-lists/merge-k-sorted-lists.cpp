/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;

        int n  = lists.size() ; 

        for(int i = 0  ; i< n ; i++){
            
            while(lists[i]){
                // ek ek ko pq me push kro then 
                pq.push(lists[i]->val) ; 
                lists[i] = lists[i]->next  ; 
                // pq me se pop kra k ll banaio
            }
        }

         // pq me se pop kra k ll banaio
         ListNode * dummy = new ListNode(0) ; 
         ListNode* tail = dummy  ; 

         while(!pq.empty()){
             int top = pq.top() ; 
             pq.pop() ; 
             tail->next = new ListNode(top) ; 
             tail = tail->next ; 

         }
   return dummy->next ;
    }
};