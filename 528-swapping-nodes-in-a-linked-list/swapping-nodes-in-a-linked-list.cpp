class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> store;
        ListNode* temp = head;

       
        while (temp != NULL) {
            store.push_back(temp->val);
            temp = temp->next;
        }

        int n = store.size();
        // Swap the k-th node from the beginning and end 
        swap(store[k - 1], store[n - k]);

        // Reconstruct the linked list with modified values
        temp = head;
        int i = 0;
        while (temp != NULL) {
            temp->val = store[i++];
            temp = temp->next;
        }

        return head;
    }
};
