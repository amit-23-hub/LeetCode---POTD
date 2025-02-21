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

        ListNode* temp = head   ;
        ListNode* prev = NULL  ;
        while(temp !=NULL){

        ListNode*  nxt = temp->next;  // Next node
        temp->next = prev;       // Reverse direction
        prev = temp;
        temp = nxt;

        }
        // ab dekhna hai agr LL k node k value se less koi hoga to delete kr deng
        ListNode* newHead = prev; // Head of reversed list
        ListNode* curr = newHead;
        
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->val > curr->next->val) {
                curr->next = curr->next->next; // Skip smaller node
            } else {
                curr = curr->next; 
            }
        }

        // Reverse back the list to restore original order
        temp = newHead;
        prev = nullptr;

        while (temp != nullptr) {
            ListNode* nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }

        return prev; 
    }
};