class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr) {

            // duplicate found
            if (curr->next != nullptr && curr->val == curr->next->val) {
                int val = curr->val;

                // skip all nodes with same value
                while (curr != nullptr && curr->val == val) {
                    curr = curr->next;
                }

                // reconnect links
                if (prev != nullptr) {
                    prev->next = curr;
                } else {
                    head = curr;
                }
            }
            // no duplicate
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
