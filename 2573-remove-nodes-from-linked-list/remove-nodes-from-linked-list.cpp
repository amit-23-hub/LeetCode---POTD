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
    ListNode* removeNodes(ListNode* head) {
        // reverse kr denge 
        ListNode* temp =  head ;
        ListNode* prev = NULL ;

        while(temp!=NULL){
            ListNode* nxt = temp->next ; 
            temp->next =  prev ; 
            prev = temp ; 
            temp = nxt  ; 

        }
        // smaller ko delete
        ListNode* newhead = prev ; 
        ListNode*   cur = newhead ; 

        while(cur!=NULL && cur->next !=NULL){
            if(cur->val > cur->next->val){
                cur->next = cur->next->next ; 
            }else{
                cur = cur->next ;
            }
        }

        // then again reverse the link;ist 

        temp = newhead ; 
       ListNode* pre = NULL ; 
        while(temp!=NULL){
            ListNode* future = temp->next ; 
            temp->next = pre ; 
            pre = temp ; 
            temp = future ;
        }

        return pre ; 
    }
};